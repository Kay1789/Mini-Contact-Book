📒 Dynamic Mini Contact Book 3.0

> A simple contact management system made with C++. Not super fancy, just straight-up terminal vibes. You can add, edit, delete, and search contacts. Plus there's some cute ASCII art to keep it fun. 😤✨

---

## 🧠 Features

- 📇 Add new contacts (name + number)
- 🔄 Edit existing ones
- ❌ Delete contacts by index
- 🔍 Search by name (partial match works too)
- 📜 View the full contact list
- 🎨 ASCII UI elements for flavor
- 🔧 Dynamically allocated arrays (choose your own contact limit)

---

## 💻 How It Works

- Uses `std::string*` dynamic arrays (`addName`, `addNumber`)
- You set the max number of contacts when it starts
- Everything is stored in RAM (no file saving yet)
- ASCII borders like `/~@~@~@~/` and bunny faces make it feel ✨alive✨

---

## 🛠️ Functions Used

| Function       | What it Does                         |
|----------------|--------------------------------------|
| `addEntry()`   | Adds a contact to the list           |
| `deleteEntry()`| Deletes a contact by index           |
| `editEntry()`  | Edits a contact's name/number        |
| `searchEntry()`| Finds a contact by name (partial ok) |
| `showEntry()`  | Lists all contacts currently saved   |
| `mainFun()`    | Menu loop to handle user choices     |

---

## 📦 Setup & Run

> You'll need a C++ compiler like g++.

```bash
g++ -o ContactBook contactbook.cpp
./ContactBook


---

🧹 Memory Management

No leaks here fam.
We free up memory at the end with:

delete[] addName;
delete[] addNumber;

C++ ain't playing when it comes to cleanup 💀


---

🎯 To-Do (Maybe, if I'm in the mood)

[ ] File saving/loading 📁

[ ] Better input validation (no 123abc as phone numbers 😩)

[ ] GUI maybe? (Terminal gang rise up)

[ ] Contact tagging or groups



---

🐰 ASCII Vibes

Yup, there’s built-in art:

/\_/\
(@ . ^)    → Welcome bunny
(｡•́︿•̀｡)  → Goodbye bunny

And a bunch of borders like |>^_^_^_^_^| cuz why not


---

👾 Credits

Made by me, duh 😎
Feel free to fork it, change it, or vibe with it.
