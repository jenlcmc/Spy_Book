# Spy book
- A simple spy book used linked list to display data of the spies.
- The user can add new inforamtions for new spies. 
- They can also display the data in tree view in order to see the relationship between spies.
- For the tree view, the relatinship is based on the agency that they worked for.
- The user can either choose between display all, display tree or go through each spy step by step.
- They can either go to previous or next spy depend on user choice. 
- The book also has search function for the user to find spy.
- User can search between first, last name, city , state/country to find the spies they want.

## About clonning

- You can clone a repository from GitHub to your local computer to make it easier to fix merge conflicts, add or remove files, and push larger commits. 
- When you clone a repository, you copy the repository from GitHub to your local machine.
- Cloning a repository pulls down a full copy of all the repository data that GitHub has at that point in time, including all versions of every file and folder for the project. 
- You can push your changes to the remote repository on GitHub, or pull other people's changes from GitHub. For more information, see "Using Git".
- You can clone your existing repository or clone another person's existing repository to contribute to a project.

## To clone 

- Open Terminal.
- Change the current working directory to the location where you want the cloned directory.

```
$ git clone https://github.com/jenlcmc/Spy_Book.git
```

- Press Enter to create your local clone.
- It shoud kind of look like under example except the https is different

```
$ git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY
> Cloning into `Spoon-Knife`...
> remote: Counting objects: 10, done.
> remote: Compressing objects: 100% (8/8), done.
> remove: Total 10 (delta 1), reused 10 (delta 1)
> Unpacking objects: 100% (10/10), done.
```

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
