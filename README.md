# 🐚 **Minishell**  
**As beautiful as a shell** ✨  

Minishell is a minimalist yet powerful shell designed to replicate and enhance the basic functionalities of bash. With an emphasis on simplicity, speed, and adherence to UNIX principles, Minishell provides a streamlined, interactive shell experience.  

![Minishell Logo](https://github.com/amirkhanyan11/minishell/blob/master/img/img1.png)

## 🌟 Key Features  
- **🖥️ Interactive Command Line**  
  - Display a customizable prompt.  
  - Persistent command history for seamless navigation.  

- **⚙️ Executable Management**  
  - Locate and execute programs using the `PATH` environment variable or relative/absolute paths.  

- **💬 Quoting Support**  
  - Handle single (`'`) and double (`"`) quotes for precise command interpretation.  

- **🔄 Redirections**  
  - Input `<`, output `>`, append `>>`, and heredoc `<<` supported seamlessly.  

- **🔗 Pipes**  
  - Chain commands using pipes (`|`) with efficient data streaming.  

- **🌱 Environment Variable Expansion**  
  - Expand variables using `$` syntax for dynamic command execution.  

- **🚦 Exit Status Management**  
  - Retrieve the last executed command’s status using `$?`.  

- **⚡ Signal Handling**  
  - Graceful handling of `Ctrl-C`, `Ctrl-D`, and `Ctrl-\`, emulating bash's behavior.  

- **🔧 Built-in Commands**  
  - `echo` with `-n` flag.  
  - `cd` for directory navigation.  
  - `pwd` to display the current directory.  
  - `export` to set environment variables.  
  - `unset` to remove environment variables.  
  - `env` to display the current environment.  
  - `exit` to terminate the shell.

## 🛠️ Installation  

### 📋 Requirements  
- GCC or Clang compiler  
- GNU Make  
- A UNIX-like operating system (Linux, macOS, etc.)  


## 🏗️ Build Steps

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/minishell.git
   cd minishell
   ```

2. **Build the project**:
   ```bash
   make
   ```

3. **Run the shell**:
   ```bash
   ./minishell
   ```

4. **Clean the build files**:
   ```bash
   make clean
   ```

---

## 📚 Usage

Once inside Minishell, type your commands just as you would in bash. Enjoy a clean, efficient command-line interface with full control over your system. ✨

---

## 🤝 Contributing

Contributions are welcome! 💡 Follow these steps:

1. Fork the repository. 🍴
2. Create a new branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m 'Add feature'
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Open a Pull Request. 🛠️

Please ensure your code adheres to the coding standards and includes necessary documentation. ✅

---

## 📜 License

This project is licensed under the [MIT License](LICENSE). 📝

---

## 🙏 Acknowledgments

Inspired by the UNIX philosophy and the need for simplicity in software. 🌟


