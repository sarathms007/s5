// Dining Philosophers problem
 /*
Five philosophers are seated around a circular table. A fork is placed between each
pair of adjacent philosophers.Each philosopher must alternately think and eat.A philosopher
can only eat when he has both left and right forks.Each fork can be held by only one
philosopher and after he finishes eating he has to put down both forks so they become
available to others. We have to devise an algorithm for allocating forks among philosophers
in a manner such that each philosopher won't starve . */


//Solution
/*
Pick up the left fork; if the right fork isn’t available for a given time, put the left fork down,
wait and try again. Still, even if each philosopher waits a different random time, an
unlucky philosopher may starve.
Require all philosophers to acquire a binary semaphore before picking up any forks. This guarantees that no philosopher starves (assuming that the semaphore is fair) but limits parallelism dramatically.
*/



//Code
#define N 5 /* Number of philosphers */
#define RIGHT(i) (((i)+1) %N)
#define LEFT(i) (((i)==N) ? 0 : (i)+1)

typedef enum { THINKING, HUNGRY, EATING } phil_state;
phil_state state[N];
semaphore mutex =1;
semaphore s[N]; /* one per philosopher, all 0 */


void test(int i)
{
if((state[i]==HUNGRY)&&(state[LEFT(i)]!=EATING)&&(state[RIGHT(i)]!=EATING)
{
state[i] = EATING;
V(s[i]);
}
}

void get_forks(int i)
{
 P(mutex);
 state[i] = HUNGRY;
 test(i);
 V(mutex);
 P(s[i]);
}

void put_forks(int i)
{
P(mutex);
state[i]= THINKING;
test(LEFT(i));
test(RIGHT(i));
V(mutex);
}

void philosopher(int process)
{
 while(1)
  {
  think();
  get_forks(process);
  eat();
  put_forks(process);
  }
}

/*
When a philosopher is hungry he uses test to try to eat. If test fails, he waits on a semaphore until some other process sets his state to EATING. Whenever a philosopher puts down forks, he invokes test in his neighbors.
So this code is somewhat obscure. And more importantly, it doesn’t encapsulate
the Philosopher - philosophers manipulate the state of their neighbors directly. If we don’t want to touch other processes’ state, we can always do the V to the left and right when a philosopher puts down the forks.

*/


