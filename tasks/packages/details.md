# Packages

- List all packages
- Find packages on the basis of their installation method, that is, what package manager was used
  - Like `snap`, `flatpak`, `appimage`
  - While all the rest default package managers, like `pip`, `npm`, `rhel`, `zypper`, `dnf`, `pacman` just fall into one list called `packages`.
- We can assume safely that each pkg manager has their own way of installing packages. 
- We must emphasize on the above point so we can easily differentiate which package comes from where
- As far as the UI is concerned, make each package be on a single row, with,
  - `remove`, and `update` options
- Look at possible package manager conflicts