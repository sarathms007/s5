//SLEEPING BARBER’S PROBLEM
/*
The barber shop has one barber,one barber chair and a waiting room with a
number of chairs in it.When the barber finishes cutting a customer's hair he
dismisses customer and checks waiting room.If there are customer's waiting,he
brings one of them back to the chair and cuts his hair.If there are no other
customers waiting he sleeps in his chair.The problems include
1) A customer may arrive and observe that the barber is cutting hair, so he goes to the waiting room. While he is on his way, the barber finishes the haircut he is doing and goes to check the waiting room. Since there is no one there (the customer not having arrived yet), he goes back to his chair and sleeps. The barber is now waiting for a customer and the customer is waiting for the barber.
2) Two customers may arrive at the same time when there happens to be a single seat in the waiting room. They observe that the barber is cutting hair, go to the waiting room, and both attempt to occupy the single chair.

*/


//Solution
/*The following code illustrates the solution by implementing binary semaphores.*/

//code


Semaphore Barber = 0;
Semaphore Customers = 0;
Sempahore Mutex = 1;
int ChairsAvailable = 3;

BarberShop()
{
while(TRUE)
{

// Wait for customers to arrive

P(Customers);

// Update the number of chairs available
P(Mutex);
ChairsAvailable++;

V(mutex);

//cut hair
// Signal that the barber is done
V(Barber);
}

}

Customer()
{
Boolean HairWasCut = false;
P(mutex);
if (ChairsAvailable != 0)
{
ChairsAvailable--;
V(Mutex);

// Signal that there is a customer in a chair
V(Customers);

// Wait for a barber to cut hair
P(Barber);
//The customer’s hair is cut

}

else //no free chairs available
{
V(mutex);
}

}
