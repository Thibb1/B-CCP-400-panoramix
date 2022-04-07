# Panoramix

## Usage

```bash
./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```

- **nb_villagers**: indicates the number of villagers (must be >0);
- **pot_size**: indicates the maximum number that can be contained in the cooking pot (must be >0);
- **nb_fights**:indicates the maximum number of fights a villager will engage in (must be >0);
- **nb_refills**: indicates the maximum number of time the druid will refill the pot (must be >0).

The program must follow these rules:

- You **MUST** make use of semaphores;
- You **MUST** make use of mutexes;
- Each villager (and the druid) **MUST** run in its own thread;
- The cooking pot is full at the start of the program:
- A villager’s thread must stop when all the fights have been done (and hopefully won);
- The druid’s thread must stop when he has no ingredients left (aka: _nb_refills_) to refill the pot;
- The program must stop gracefully when all the villager’s threads have stopped

## Villager

Each villager is identified by an id (a number unique to the villager). It will fight _nb_fights_ time before leaving
the battlefield. Before each fight, it must take a serving of magical potion from the pot (if the pot is empty,
it must inform the druid and wait until the pot is refilled).

> A villager cannot fight without having drank some potion first!

You **MUST** display the following messages on the standard output, when the corresponding event occurs:

- When a villager thread starts

`Villager <id>: Going into battle!`

- When a villager tries to drink some potion

`Villager <id>: I need a drink... I see <nb_servings_left> servings left.`

- When a villager call the druid for a refill

`Villager <id>: Hey Pano wake up! We need more potion.`

- When a villager is fighting

`Villager <id>: Take that roman scum! Only <fights> left.`

- When a villager has done all is fights

`Villager <id>: I'm going to sleep now.`

> There are cases when villagers may wait endlessly. Can you see which ones? We’re not speaking about deadlocks...
 
## Druid

The druid will wait to be called by a villager; then it will refill the pot with _pot_size_ servings. When _nb_refills_ have been done, the druid has run out of ingredients and it’s thread must stop.

>It may be a good idea to inform the villagers that the pot has been refilled.

You **MUST** display the following messages on the standard output, when the corresponding event occurs:

- When the druid thread starts

`Druid: I'm ready... but sleepy...`

- When the druid is called to refill the pot

`Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make <refills> more refills after this one.`

- When the druid runs out of ingredients

`Druid: I'm out of viscum. I'm going back to... zZz`
