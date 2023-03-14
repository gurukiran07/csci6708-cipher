# CSCI 6708 - Assignment 4

## File structure:

```
code
├── Makefile
├── README.md
├── headers
│   ├── playfair.h
│   └── transposition.h
├── plain-text.txt
└── src
    ├── main.cpp
    ├── playfair.cpp
    └── transposition.cpp
```

`.cpp` files are inside `src/` folder and all the header are inside `headers/` folder. The input text `plain-text.txt` is in the top-most directory `code/`.

## Setup the code

Download the file and maintain the above file structure. The files are uploaded to brightspace, github and git.cs.dal.ca.

- [`Github repo`]()
- [`git.cs.dal.ca repo`]()

```
$ git clone 
```

## Running the code

After cloning or downloading from brightspace change into `code/` directory. Now, run `make` to compile and run the code.

```
$ cd code/
code/ $ make
```

## Testing the code

- To test with custom plain text edit the `plain-text.txt` file and run `make` command.