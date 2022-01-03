# MASTERMIND - Game project for university

 This is a little project we are writing for university. It's the game **Mastermind** also known as *SuperHirn*, *Super Code*, *Variablo* and *LogikTrainer*.
 The code is completely written in C according to the C89 standard and it's only using the C89 standard library.

## :jigsaw: Easy expandability

 It's quite easy to add a new language. The GUI will automatically include your added language if you follow these steps.
 1. **mastermind_language.h**
    - Define a new constant like *#define LANGUAGE_SPANISH 3*.
    - Increment the constant *AMOUNT_OF_LANGUAGES*.
 2. **mastermind.c**
    - Add a new case with your language to *language_menu()*.
 3. **mastermind_language.c**
    - Add a new case into every function with your translation.


## :busts_in_silhouette: Team
 The Team consists of [alpha-kappa-de](https://github.com/alpha-kappa-de), [Jooosy](https://github.com/Jooosy) and [JanisNoah](https://github.com/JanisNoah).
