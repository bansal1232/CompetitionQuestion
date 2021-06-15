
Design the game of monopoly/business
- players get 10k to begin with (2-3)
- Type of property are hotels (15), fillers (10) and parks/jails (5)
  - hotel you pay to the owner
  - park jail you pay to game
  - filers does nothing

- You can only buy hotels they cost Rs 1000
- Rent is awalays constant to Rs 500
- Winner is one with max amount in pocket + assets

what to do
  - define the enity with there property and functions
  - Money should be traced at all time
  - Write sudo code for a dry run for 2 turns each

- out of scopete
  - cant build houses

Game {
  List<Players> players;
  Board ;
  List<Property>;
  
  GameStatus:
  
  boolean gameOver();  
}

4 -> 

00 01 02
10 11 12
20 21 22



Cell {
  
}

Board {
  int size=4;

  
  getTotalCells(){
    return size * size - 2;
  }
  
  List<Propety> 
  
}

class Property{
  Name
  Cost
  Rent
  Player;
  
  
  
}

Player{
  STATUS
  money;
}


int getNumberRollDice() {
  return randomNumber();
}

p = board.getProperty(position)
if p.type == Hotel:
  if(p.owner != null) { //already bought
      if( p.owner != curr_player) { // play rent
        curr_player.money -= propert.rent;
        p.player.money += ropert.rent;
  }
  
  }
  else {
    // buy property
    curr_player.money -= property.cost;
    Game.
    propert.owner = curr_player;
  }

mysql 
postgres 


d = jdbcDriver.connect()

d.connect()
d.commit()

games {
  p[hteo, tese, jain filter]
  
  p.play(player)
  
}

cplay() {
  asda
  
  asas
  asfaf
  asf
}



filler.play{
  do nothing
}



teasre.play() {
  asdasd
  asdasd
}


interface messanger {
  void message(str msg)
}

contact implements messanger {
  private name;
  void contact(str name) {
    ..
  }
  void message(str msg) {
    // messenger implementaion
    print('msg to %s is %s:',this.name, msg);
  }
}

Group implements messanger {
  list messanger msgs
  Group(){}
  add(message) {
    msg.add(message)
  }
  Message(msg) {
    for(c: msgs) {
      s.message();
    }
  }
}
client {
  c1 = new contact('contact1')
  enc_c1 = new encrpt(c1);
  com_enc_c1 = new Compress(enc_c1);
  c2 = new contact('contact2')
  cmp_c2 = new Compress(c2);
  c3 = new contact('contact3')

  c1.message('hello')
  c2.message('hello')
  c3.message('hello')
  
  List
  grp = group();
  grp.add(c1)
  grp.add(c2)
  grp.add(c3)
  
  
  
  grp.messang();
  

  // how can you optimise this code so that the client makes only one call

  // how can you send c1 encrypted message with minimal regression
  grp.add(enc_c1)
  grp.add(c2)
  grp.add(c3)
  
  
  
  grp.messang();
  
  // how can you send c2 compressed message with minimal regression
  grp.add(enc_c1);
  grp.add(cmp_c2);
  grp.add(c3)
  
  enc_grp = new encrpt(grp);
  enc_grp.messeng(msg)
  
  grp.messang();
  
}


encrypt implements messanger {
  private Messenger mesg;
  encrypt(Messenger msg){
    this.mesg = msg;
  }
  ...
  void message(str msg) {
    // messenger implementaion
    mesage = enctrp(msg);
    mesg.message(mesage)
  }
}

Compress implements messanger {
  private Messenger mesg;
  Compress(Messenger msg){
        this.mesg = msg;
  }
  ...
  void message(str msg) {
    // messenger implementaion
    mesage = Compress(msg);
    mesg.message(mesage)
  }
}


