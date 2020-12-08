# COVID-19-Agent-based-Network-Model

## Introduction
The COVID-19 virus has been spreading rapidly throughout the world. At a time that no reliable vaccine or effective treatment has been developed, mathematic models and computer simulation can help us to better understand the spread of the disease, as well as give insights into how to take precise and effective precaution measures to control the spreading.
 
The purpose of this project is to build a program that simulates COVID-19 transmission in a population, using parallel programming techniques. The output of the project is an estimation and representation of the workings of contagion, recovery, and death in the pandemic.

## Team B
Tech lead: Ziqi Tan

| Member      | BU ID       | Email           |
|-------------|-------------|-----------------|
| Kaijia You  | U 44518396  | caydenyo@bu.edu |
| Peiqing Lu  | U 93836939  | lujason@bu.edu  |
| Tian Ding   | U 90706530  | dingtian@bu.edu |
| Xiaoxin Gan | U 98012154  | xiaoxing@bu.edu |
| Xueyan Xia  | U 82450191  | xueyanx@bu.edu  |
| Zhelin Liao | U 11064341  | seanliao@bu.edu |
| Ziqi Tan    | U 88387934  | ziqi1756@bu.edu |

## Task Instructions
- The results can easily be recognized as a representation of the workings of contagion, recovery, and death in the pandemic. The graph of new infections, for instance, should have a shape that resembles the curve produced by other standard simulations.

- The primary aim of this project is **not** to have an impressive performance or to have a simulation so realistic as to provide accurate numerical predictions, but rather to give you a good learning experience in the design of a simulation **from scratch** and its implementation by means of the standard parallel programming techniques we have learned in the course.

- The simulation should take into account social networks.  The social networks may be created randomly but should not wind up being completely connected graphs.

- Do not go shopping for ready-made, specialized libraries and software packages designed for the simulation of epidemics.  Instead, build your simulation and your implementation from the ground up.

## Epidemiology Terms
- **Susceptible** individual: a member of a population who is at risk of becoming infected by a disease.
- **Asymptomatic carrier** (healthy carrier or just **carrier**): a person or other organism that has become infected with a pathogen, but that displays no signs or symptoms.
- **Pathogen**: any organism that can produce disease.
- **Incubation period** is the time elapsed between exposure to a pathogenic organism, a chemical, or radiation, and when symptoms and signs are first apparent.

## System Model

We are going to use **an agent-based network model** to simulate the process and outcome of the spread of the COVID-19. Our COVID-19 model is based on the SIR model (Susceptible, Infectious, Recovered), which will be briefly discussed first. Then, 

### Basic SIR Model

- **Susceptible**: The number of susceptible individuals. 
- **Infectious**: The number of infectious individuals.
- **Recovered**: The number of removed (and immune) or deceased individuals.

To represent that the number of susceptible, infectious and removed individuals may vary over time (even if the total population size remains constant), we make the precise numbers a function of t (time): S(t), I(t) and R(t). We use the following ordinary differential equations to describe this process.

$$
\frac{dS(t)}{dt} = -\alpha S(t) I(t)
$$

$$
\frac{dI(t)}{dt} = \alpha S(t) I(t) - \beta I(t)
$$

$$
\frac{dR(t)}{dt} = \beta I(t)
$$

$$
0 < \alpha < 1 
$$

$$
0 < \beta < 1
$$

where alpha is the transmission rate and beta is the recover rate.


### COVID-19 Pandemic Model

#### Social Network Model
The traditional network-based SIR model assumes a 'homogeneous mixing', which means that any pair of members are equally like to interact with each other. This model deviates from the real-life situation because human interaction is constrained under different circumstances. 

In this project, we adopt a social network model instead, to depict the social connection between members. Define social network as a graph G(V, E), each node V denotes an agent, each edge E denotes the direct social connection between two agents. Meanwhile, we can represent this graph using the adjacency matrix, as well as calculate the shortest path between two nodes and its distance Dmin(Vi, Vj).  

The probability of one-on-one interaction :

P{ Agent i interact with Agent j } =   
                                       δ/Dmin(Vi, Vj)  when Dmin(Vi, Vj) != ∞
                                       ρ               when Dmin(Vi, Vj)  = ∞
                                       
Two individuals with closer proximity in the graph have a higher encounter probability, contrarily individuals with no direct or indirect connection have a low probability of meeting. We can use this as an reference to model the interaction and generate the social events.

#### Agent Model
We use the term 'agent' to describe an individual. An agent should maintain a wellness state and a schedule table.

- **Wellness state** 
We use Finite State Machine to represent the transmission of en agent's wellness state
There are different states under the Covid-19 pandemic as follow: 

   - **Exposed**: an individual in the exposed state has contracted the virus and will become a presymptomatic carrier or an asymptomatic carrier.
   - **Presymptomatic**: not yet displaying symptoms of an illness or disease.
   - **Asymptomatic**: not causing, marked by, or presenting with signs or symptoms of infection, illness, or disease. 
   - **"Mild"** and **"Severe"** are symptomatic states. Individuals with mild symptoms may get **"Recovered"** or get **"Severe"**. Those in the **"Severe"** state may have a certain **mortality** rate.
   - **Recovered**: an individual who has recovered from COVID-19 will not get infected again.
![alt finite-state-machine](./images/finite-state-machine.png)

- **Agent Schedule** 
The agent maintains a schedule object which is a list of events and it can map from time to activity. The scheduling interval is one hour. Each agent can only have one activity within the time interval.

For future extension: we can include attributes such as age and underlying health condition to model the virus contraction rate and mortality rate.

#### Event Model
To simplify social interaction, we only consider two scenarios:
   - meeting other people (with social event)
   - stay alone (without social event, i.e. quarantine)

For future extension: we can extend event class to differentiate social events from different social network models and virus contraction rates such as public transportation events, class events, and dining events.

#### Predefine Model Constraints
1. The number of the population remains constant. The model simulates the pandemic in such a short period that births and deaths (other than deaths caused by the COVID 19) can be neglected.
2. COVID-19 can be spread 2 days after a person is exposed to the virus.  COVID-19 can also be spread from presymptomatic and asymptomatic individuals.
3. People who contact with infected individuals may get infected with a contraction rate. The contraction rate is diffrent in different wellness state.
4. COVID-19 cannot spread among individuals who are in a quarantine state.
5. The incubation period is typically around 5 days but may range from 1 to 14 days.
6. Every individual only has one event each hour to avoid competition.


### Model Implementation

#### Object-Oriented Design
- Agent and event class is designed for facilitating future extensions to its variants.
- Use an ajacency matrix(array) to represent agent social network.
- A global clock whose time interval is an hour.
- Wellness statu is designed as enumeration type which is open for future extensions

```
class Agent {
    Event* schedule = new Event[100];   // can index activity using timestamp
    enum wellness;
}

Agent* network = new Agent[1000000];  // a representation of social network using adjacency matrix 

class Event {
    Time timestamp;
    Agent* paticipants;
    
}
```

#### Parallel Computing Technology
- C++ and OpenMP/CUDA. (Try OpenMP first)
- Each thread takes care of an agent.
- Each agent polls the clock.

#### Main Flow
```
Initialize the network.
Initialize the agent and its initial wellness state.
Initialize the schedule for each agent.

global clock = 00:00, day 1
global DURATION = 20 days

Loop:
    Every agent retrieves its current event (if any) in parallel.
    // threads join here

    Every agent updates the state in parallel.
    // threads join here

    clock = clock + 1 hour

    if pass 24 hours:
      Calculate statistic in parallel;
      Output statistic.
      
until the end of the 20 days
```
- Example of inside a loop:
    1. Person A state: susceptible, Person B state: mild
    2. At 8:00 AM, A and B had a meeting. A got infected.
    3. A.nextState = exposed
    4. At 8:59 AM, update the state of A and the state of B.
    5. A.state = exposed, B.state = mild.
    
#### The change of infection rate 
TODO

#### The precaution strategies
1. Mask.
2. Social distance.

## Statistic
Statistics and plots.

## Test

## Collaboration

| **Person in charge** and Participants | Division of labor |
|---------------------------------------|-------------------|
| Ziqi Tan       | Tech lead.        |
| Zhelin Liao       | Presentation.     |
| **Xueyan Xia**, Ziqi Tan | System design, Model integration and parallel computing design. |
| **Tian Ding**, Zhelin Liao       | Event design and programming. |
| **Kaijia You**, Peiqing Lu| Agent object-oriented design and programming. |
| Xiaoxin gan | Test the model. Use different parameters to run the simulation.  Statistics and plotting, performance evaluation. |

The **Bold name** is the name of the person in charge.

## References

[1] Wikipedia, Compartmental models in epidemiology

[2] Katia Bulekova, Brian Gregor, Eric D. Kolaczyk, Wenrui Li, and Laura White, Github project BU-COVID, August 3, 2020.

[3] Systems Sciences at SIS, A networked SIR model, http://systems-sciences.uni-graz.at/etextbook/networks/sirnetwork.html

[4] Wikipedia, COVID-19 pandemic
