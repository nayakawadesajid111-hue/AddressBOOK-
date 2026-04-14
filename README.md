# 📒 Address Book — C Project

A command-line **Address Book application** built in C that allows users to manage their contacts efficiently with features like adding, searching, editing, and deleting contact records.

---

## 📌 Features

- Add new contacts (name, phone number, email, address)
- View all saved contacts
- Search contacts by name or phone number
- Edit existing contact details
- Delete a contact
- Data persistence using file storage (`.txt` / `.dat`)

---

## 🛠️ Built With

- **Language:** C
- **Compiler:** GCC
- **Storage:** File I/O (binary/text file)
- **Platform:** Linux / Windows / macOS

---

## 📂 Project Structure

```
addressbook/
├── main.c          # Entry point
├── contact.c       # Core contact operations
├── contact.h       # Header file with structs and declarations
├── file.c  # File read/write operations
├── file.h  # Header for file operations
├── contacts.dat    # Data file (auto-generated at runtime)
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites

Make sure you have GCC installed:

```bash
gcc --version
```

### Clone the Repository

```bash
git clone https://github.com/your-username/addressbook.git
cd addressbook
```

### Compile

```bash
gcc -o addressbook main.c contact.c file_handler.c
```

### Run

```bash
./addressbook
```

> On Windows:
> ```bash
> addressbook.exe
> ```

---

## 💻 Usage

Once the program runs, you'll see a menu like:

```
========== Address Book ==========
1. Add Contact
2. View All Contacts
3. Search Contact
4. Edit Contact
5. Delete Contact
6. Exit
==================================
Enter your choice:
```

Use the number keys to navigate through the options.

---

## 📸 Sample Output

```
----- Contact Details -----
Name    : John Doe
Phone   : +91-9876543210
Email   : johndoe@example.com
Address : Pune, Maharashtra
---------------------------
```

---

## 🧠 Concepts Used

- Structures (`struct`) for contact data modeling
- File I/O (`fopen`, `fread`, `fwrite`, `fclose`)
- Dynamic memory management (`malloc`, `free`)
- String operations (`strcmp`, `strcpy`, `strstr`)
- Modular programming with multiple `.c` and `.h` files

---

## 🐛 Known Issues / Limitations

- No duplicate contact detection (can be added as an enhancement)
- Limited to a fixed number of contacts if using arrays (use linked list for dynamic storage)

---

## 🔮 Future Enhancements

- [ ] Sort contacts alphabetically
- [ ] Export contacts to CSV


---

## 🤝 Contributing

Contributions are welcome! Feel free to fork this repository, make changes, and submit a pull request.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/your-feature`)
3. Commit your changes (`git commit -m 'Add some feature'`)
4. Push to the branch (`git push origin feature/your-feature`)
5. Open a Pull Request

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 👤 Author

**Your Name**  
GitHub: [@your-username](https://github.com/your-username)

---

> ⭐ If you found this project helpful, please give it a star!
