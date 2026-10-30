# biggest square
(also called the settingup in Epitech)

This project was one of my first c projects that I ever did (that's why the code looks so bad). However, even though its old code, it has no mem leaks nor valgrind issues.

I've recently updated the code to make it slightly faster and more readable, as well as making a flame_graph of the code to see where the bottlenecks were. (go see docs/ for the svg)


You can run the code by running the following command in the terminal:

```bash
make && ./biggest_square 5000 ....o..o....o #this generates its own map of 5000x5000 with pattern provided and finds the biggest square in it, but you can also use your own map by replacing the 5000 ....o..o....o with your own map file
```
