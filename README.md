<h1 align="center">PIPEX</h1>

## Index

- [Index](#index)
- [Description :clipboard:](#description-clipboard)
- [Usage](#usage)
- [Operation :wrench:](#operation-wrench)
- [Learnings :brain:](#learnings-brain)
- [Author](#author)

## Description :clipboard:
<p>

Pipex is a command-line program designed to replicate the functionality of the Unix pipe operator `|`. It aims to implement a simplified version of the pipe mechanism used in Unix-based systems, allowing the user to redirect the output of one command as input to another command.

For more information about the project check the [subject here](https://github.com/pedromessetti/pipex/blob/master/subject.pdf). The program was written following the rules described in the 42 Norme. To check the Norme [click here](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).
</p>

## Usage
<p>

Clone the repository and `cd` in the project folder.

Type `make` on the command line. 

To use the program type in the command line: 

`./pipex input_file cmd1 cmd2 ... output_file`

You can provide any number of shell commands, and the program will work as the following command line in bash:

`< input_file cmd1 | cmd2 | ... > output_file`

The program takes at least four arguments: an input file, two (or more) commands and an output file. It reads the content of the input file and feeds it as input to the following commands. The output of command1 is then passed as input to command2 and so forth. Finally, the output of the last command is written to the output file.

The program handles absolute paths, multiple pipes, heredoc inputs, incorrect commands, flags, paths, and non-existing input files or directories.

</p>

## Operation :wrench:

<p>

At start, the program first checks if the argument count is more than five. Then tries to open the input file in read-only mode using `O_RDONLY` flag, in case of fail, the program creates a temporary hidden file with no content to continues his execution. If not already exists, creates the output file with the following flags:
- `O_CREAT` => Create a new file if it doesn't already exists, need an additional argument to the `open()` function to specify the permissions. In this case will be 0644.
- `O_WRONLY` => Open in write-only mode. Means that the program can write data but cannot read from it.
- `O_TRUNC` => Truncate the file if already exists. Means that the content of the file will be overwrited.

Now the program will handle the commands or absolute paths passed as arguments. If it's a command, set a bidimensional array of all the possible paths that are getter from `envp` making a string join of the possible path, the slash character "/" and the respectevly command. Then try to access that new generated path with `access()` function, in sucess the path is stored in the tail of a linked list, if couldn't access means that is not a executable command and prints the aproprieted error message. In the case of the argument is an absolute path, the behavior is the same but without the `envp` check.

After reciving and check all the commands and paths the program starts the child process, one for each command and correctly choosing wich file descriptor will be duplicated or closed in each process. Then execute the command on the given file descriptor, passing the write end for the parent process and waits for the child to terminate. At the end, free the allocated memory for the linked list and unlink the temporary input file if exists. 
</p>

## Learnings :brain:

<p>

- `envp` => Environment pointer it's used to pass the environment variables to a program when it is executed. The envp parameter is an array of strings, where each string represents an environment variable in the format "variable=value". The last element of the array is typically a NULL pointer, indicating the end of the list of environment variables.

- `fork()` => Function used to create a new process by duplicating the existing process, creating a child process that is an exact copy of the parent. The new process starts immediately after the function call, but in a separate memory space. It will return twice: once in the parent process and once in the newly created child process. In the parent, the return value is the process ID of the child process. This allows to track and manage the child process. In the child, the return value is 0 and the program uses this information to differentiate from the parent process.

    The child process receives a copy of all the variables, file descriptors, and other resources from the parent, however modifications made in one process don't affect the other process. This function is a fundamental building block for creating new processes in a C program. It enables parallelism, multiprocessing, and the execution of complex tasks by dividing them into multiple processes.

- `waitpid()` => Function commonly used in combination with `fork()` to wait for the child process to end. It allows the parent process to synchronize its execution and obtain information about the child process that has finished. The function is called by the parent process and takes three parameters: the pid of the child process to wait for, a pointer to an integer where the exit status of the child will be stored (NULL if doesn't need to store) and flags that control the behavior of the function. If the pid specified is -1, the function waits for any child process to terminate. If is greater than 0, the function waits for the child with the specified pid to terminate. If the pid is 0, the function waits for any child to finish.

    When calling the function inside of a loop, the parent process wait for multiple child processes to end, collect their exit status code and perform necessary cleanup or further processing. If successfully waits for a child process to end, it returns the pid of the terminated process, in case of an error, it returns -1.

- `pipe()` => Function that is also commonly used with `fork()` to create a unidirectional communication channel between two related processes. It provides a way for the processes to communicate by connecting the standard output of one process to the standard input of another process. When the function is called, a pipe is created, which consists of two file descriptors: one for the read end of the pipe and other for the write end. The function takes an array of 2 integers as a parameter where the file descriptors will be stored. The read end of the pipe, `pipefd[0]`, is used for reading data while the write end, `pipefd[1]`, is used for writing data to the pipe.

- `dup2()` => Function used to duplicate a file descriptor, allowing it to refer to the same file or resource as another file descriptor. It provides a way to redirect input or output from one file descriptor to another. When used in combination with `pipe()`, creates a pipeline of processes, where the output of one process is connected to the input of another process. If fails, it returns -1.

- `exec()` family => These functions are used to execute a new program from within a C program, replacing the current process image with a new process image loaded from the specified executable file. Pipex program uses `execve()`.

- InterProcess Communication (IPC) => Refers to the mechanisms and techniques used for communication and data exchange between separate processes in an operating system. It allows processes to cooperate, share information, and synchronize their activities. In the case of this program, the communication is made using pipes.

</p>

## Author
| [<img src="https://avatars.githubusercontent.com/u/105685220?v=4" width=115><br><sub>Pedro Vinicius Messetti</sub>](https://github.com/pedromessetti) |
| :---------------------------------------------------------------------------------------------------------------------------------------------------: |