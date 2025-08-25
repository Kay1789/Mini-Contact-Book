Dynamic Mini Contact Book 4.0.1 Beta "Colorful Terminal Edition” 🌈

A dynamic, modular C++ console contact book with color-coded output, built for easy management of your contacts. Inspired by Pomcat vibes, with ANSI color support and simple ASCII art for fun!


---

Features

✅ Core Features

Add Contacts – Enter Name, Email, and Phone Number. Automatically increases your contact count.

Display Contacts – View all your contacts in a clean color-coded table.

Edit Contacts – Modify Name, Email, or Number of any contact.

Delete Contacts – Remove contacts by selecting the index, with validation to prevent mistakes.

Search Contacts – Find contacts by Name, Email, or Number (simple substring match).


🎨 Visual Enhancements

ANSI color-coded output using macros and optional RGB values for custom colors:

Headers / titles: Blue

Input prompts: Cyan

Success messages: Magenta

Errors: Red


ASCII art for welcome and exit messages

Visual separators (=======) to make menus and messages clean and readable


🔧 Technical Details

Dynamic memory allocation using std::string* arrays

Handles edge cases like invalid indices for edit/delete

Fully modular functions for each CRUD operation

Compatible with 24-bit RGB colors in supported terminals


💡 Notes

Maximum contact count is defined at runtime, making the app fully dynamic

Uses std::getline with std::ws to handle whitespace input properly

Uses std::toupper and switch-case for clean menu input handling



---

How to Run

1. Clone or download the repository.


2. Compile using a C++11 (or later) compatible compiler:

g++ -std=c++11 ContactBook.cpp -o ContactBook


3. Run the program:

./ContactBook


4. Follow on-screen prompts to add, edit, search, display, or delete contacts.




---

Example Menu

======= Main Menu =======
Add Contact [A] 
Remove Contact [R] 
Edit Contact [E] 
Search Contact [S] 
Display Contact [D] 
Quit [Q]

All input is case-insensitive

Contact indices start at 1

Invalid inputs are highlighted in red



---

Future Improvements

Use std::vector<std::string> instead of raw pointers for easier resizing

Improve search to handle spaces and case-insensitive queries

Align display columns with std::setw for cleaner output

Optional: Add gradient / rainbow menus using ansi_rgb



---

Credits

Inspired by previous versions (3.0 and earlier)

Implemented and polished by Nyx

ANSI color ideas adapted from terminal escape sequences



---