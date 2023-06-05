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
This project is about handling pipes.

For more information about the project check the [subject here](https://github.com/pedromessetti/pipex/blob/master/subject.pdf). The program was written following the rules described in the 42 Norme. To check the Norme [click here](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).
</p>

## Usage
<p>

Clone the repository and `cd` in the project folder.

Type `make` on the command line. 

To use the program type in the command line: 

`./pipex input_file cmd1 cmd2 ... output_file`

You can type a N numbers of commands and the program works as the following command line in bash:

`< input_file cmd1 | cmd2 | ... > output_file`

The program handles with absolute paths, wrong commands, wrong flags, wrong paths and input files that doesn't exists or are directories. The program has to have unless 5 arguments to work properly.
</p>

## Operation :wrench:

<p>

At start, the program first checks if the argument count is more than five. Then tries to open the input file in read-only mode using `O_RDONLY` flag, in case of fail, the program creates a temporary hidden file with no content to continues his execution. If not already exists, creates the output file with the following flags:
- `O_CREAT` => Create a new file if it doesn't already exists, need an additional argument to the `open()` function to specify the permissions. In this case will be 0644.
- `O_WRONLY` => Open in write-only mode. Means that the program can write data but cannot read from it.
- `O_TRUNC` => Truncate the file if already exists. Means that the content of the file will be overwrited.

Now the program will handle the commands or absolute paths passed as arguments. If it's a command, set a bidimensional array of all the possible paths that are getter from `envp` making a string join of the possible path, the slash character "/" and the respectevly command. Then try to access that new generated path with `access()` function, in sucess the path is stored in the tail of a linked list, if couldn't access means that is not a executable command and prints the aproprieted error message. In the case of the argument is an absolute path, the behavior is the same but without the `envp` check.

After reciving and check all the commands and paths the program starts the child process, one for each command and correctly choosing wich file descriptor will be duplicated or closed in each process. Then execute the command on the given file descriptor. At the end, free the allocated memory for the linked list and unlink the temporary input file if exists. 
</p>

## Learnings :brain:

<p>

- `envp` => 
- `fork()` => 
- `pipe()` => 
- `dup2()` => 
- `unlink()` =>
- built-in commands => 
- internal process => 
- exec family => 
</p>

## Author
| [<img src="https://avatars.githubusercontent.com/u/105685220?v=4" width=115><br><sub>Pedro Vinicius Messetti</sub>](https://github.com/pedromessetti) |
| :---------------------------------------------------------------------------------------------------------------------------------------------------: |