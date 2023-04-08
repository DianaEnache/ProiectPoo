# ProiectPoo
## Cinema management system
This program is a cinema management system, which allows clients to create a user profile, reserve cinema seats, view cinema and movie lists, and get ticket details.

The program is written in C++ and uses object-oriented programming concepts. The main classes used are Client, Film, Bilet, Angajat,Cinema,Rezervari and Bilet.

## A list of classes that have been implemented:
- Client
  - The purpose of this class is to store information related to a client. It includes various private data members such as the client's last name, first name, age, email address, and payment method (either cash or card payment).
- Film
  - The purpose of this class is to store information related to a movie such as the movie name, movie category, rating, duration of the movie, program of screening, and the client (which is an instance of the Client class). 
  - Additionally, it includes function to determine if a person is allowed to watch a horror movie, depending on whether they are below or above 18 years of age.
- Bilet
  - The purpose of this class is to store information related to a ticket. It includes various private data members such as row,seat,hall,VIP,ticket price and client(which is an instance of the Client class).
  - Additionally, it includes a function for calculating ticket price with a discount for young clients ( discount of 50% for clients under 16 years old).
- Angajat
  - This class is defined to store data about an employee. It contains private data members such as the employee's last name, first name, job position, number of months worked, salary, and personal identification number (CNP).
  - The job position can be one of the following: Cashier, Janitor, Projectionist, Cinema Manager, Receptionist, Marketing Agent, or Equipment Technician.
  - Additionally, it includes a method that calculates the employee's salary based on the number of months worked and their position.
- Cinema
  - This class is defined to store data about an employee. It contains private data members such as  cinema name, website and phone number.
- Rezervari
  - The purpose of this class is to store information related to a reservation.It contains private data members such as  the number of reserved seats, reserved seats, movie (which is an instance of the Film class),client(which is an instance of the Client class) and ticket (which is an instance of the Bilet class)
  - Additionally, it includes a methods for managing a reservation, adding and removing reserved seats, displaying reserved seats, calculating the total price of the reservation, and displaying reservation information.

# What the program can do

The program has a simple console interface, with menus that allow the user to navigate through the different options available.

## List of functionalities :
- "poateFiVizionat" -->  This function to determine if a person is allowed to watch a horror movie, depending on whether they are below or above 18 years of age.
- "CalculeazaPretBilet" --> This function calculates the ticket price based on the age of the client. If the client is under 16 years old, the ticket price is reduced by 50%, otherwise the full ticket price is returned. 
- "CalculeazaSalariu" --> This function takes in the number of worked months and the job position of an employee and returns their monthly salary based on the position.
- "adaugaLocRezervat" --> This function adds a reserved seat to a reservation. 
- "stergeLocRezervat" --> This function removes a reserved seat from the reservation list by searching for the seat number in the array of reserved seats and shifting all the elements after the removed seat one position to the left.
- "afiseazaLocuriRezervate" --> This function is used to display the reserved seats for a particular reservation.
- "calculeazaPretTotal" --> This function calculates the total price of the reservation.
- "afiseazaInformatiiRezervare" --> This function displays information about a reservation, including the name of the movie, the name of the client, the number of reserved seats, and the total price.
