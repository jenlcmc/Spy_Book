# Spy book
- A simple spy book used linked list to display data of the spies.
- The user can add new inforamtions for new spies. 
- They can also display the data in tree view in order to see the relationship between spies.
- For the tree view, the relatinship is based on the agency that they worked for.
- The user can either choose between display all, display tree or go through each spy step by step.
- They can either go to previous or next spy depend on user choice. 
- The book also has search function for the user to find spy.
- User can search between first, last name, city , state/country to find the spies they want.

## Requirements

- gcc compiler
- C++ 11 and above

## To compile the files
```
make
```

The result will be the **main** file 

## To run the file
```
./main
```

## To remove all the .o and execute files
```
make clean
```

## Remove VSCode folers

.vscode folders are used for running and debugging within VS Code text editor

.vscode folder may be hidden in Unix like system but vissible on Windows OS to find remove from terminal/powershell:

```
ls -la //.vscode folder should be visible

rm -rf .vscode
```

## Upcoming feature
- Let user search the spy and delete if they want.
