# Keep-Calm-And-Adopt-A-Pet

This is a software application for a pet shelter. The application can
be used in two modes: administrator and user. When the application is started, it will offer the option
to choose between the two modes mode:

### Version 1.0

### Administrator mode:
  The application will have a database, which holds all the animals in the shelter at agiven moment. 
The shelter administrator can update the database, meaning: add a new animal, delete a animal (when the animal 
is adopted) and update the information of a animal. Each Animal has a breed, a name, an age and a photograph. 
The photograph is memorised as a link towards an online resource (the photograph on the presentation
site of the centre). The administrators will also have the option to see all the animals in the shelter.

### User mode:
### (all of the above)

  An user can access the application and choose one or more animals to adopt. The application allows the 
user to:
  a. See the animals in the database, one by one. When the user chooses this option, the data of the
first animal (breed, name, age) is displayed, along with its photograph.
  b. Choose to adopt the animal, in which case the animal is added to the user’s adoption list.
  c. Choose not to adopt the animal and to continue to the next. In this case, the information corresponding
to the next animal is shown and the user is again offered the possibility to adopt it. This can continue as
long as the user wants, as when arriving to the end of the list, if the user chooses next, the application
will again show the first animal.
  d. See all the animals of a given breed, having an age equal or less than a given number. If the breed
is empty, then all the animals will be considered. The same options (a, b and c) apply in this case.
  e. See the adoption list.
