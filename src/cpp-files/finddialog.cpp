#include "../header-files/finddialog.h"

#include <QMessageBox>

#include "../design/ui_finddialog.h"
#include "../header-files/mainwindow.h"

#pragma region Con - De - Structors
findDialog::findDialog( QWidget* parent, QTextEdit* textFile,
                        QTextCursor cursor, QString fW )
    : QDialog( parent ), findui( new Ui::findDialog ) {
    // setup pointer for ui
    findui->setupUi( this );
    // assign constructor parameters to right variables
    fileText = textFile;
    selectCursor = cursor;
    widget = parent;
    findWord = fW;
    // connecting button to function
    connect( findui->pushFind, &QPushButton::pressed, this,
             &findDialog::pushFind );
}

findDialog::~findDialog() { delete findui; }
#pragma endregion

int findDialog::location = 0;
int findDialog::count = 0;

#pragma region functions
void findDialog::pushFind() {
    // if findWord equal to empty string(not coming from replaceDialog class)
    // findWord value will be our txtFind box's value
    if ( findWord == "" ) {
        findWord = findui->txtFind->text();
    } else {
        // else(coming from replaceDialog class) assign the values of
        // replaceDialog class's location and count value
        location = replaceDialog::location;
        count = replaceDialog::count;
    }
    // fileText's widestring value assign to Text(wide string)
    std::wstring Text = fileText->toPlainText().toStdWString();

    // find count of searched word
    if ( location == 0 ) {
        for ( size_t i = Text.find( findWord.toStdWString() );
              i != std::string::npos; i = Text.find( findWord.toStdWString(),
                                                     i + findWord.length() ) ) {
            count++;
        }
    }

    int found = Text.find( findWord.toStdWString(), location );
    // if it cannot find another...
    if ( found == -1 ) {
        QMessageBox::warning( widget, "No match",
                              "No other matches found in the text" );
        location = 0;
        selectCursor.setPosition( location, QTextCursor::MoveAnchor );
        selectCursor.setPosition( location, QTextCursor::KeepAnchor );
        // else...
    } else {
        // set the found word selected
        selectCursor.setPosition( found, QTextCursor::MoveAnchor );
        selectCursor.setPosition( found + findWord.length(),
                                  QTextCursor::KeepAnchor );
        fileText->setTextCursor( selectCursor );
        // new location will be (found location + word length)
        location = found + findWord.length();
        // set the label's text to count of remaining
        findui->countLabel->setText( "Remaining count = " +
                                     QString::number( count ) );
        // subtract the count by one
        count--;
    }
    // if function caller is replaceDialog class, assign the findDialog class's
    // location and count variables to replaceDialog's variables.
    replaceDialog::location = this->location;
    replaceDialog::count = this->count;
}
#pragma endregion
