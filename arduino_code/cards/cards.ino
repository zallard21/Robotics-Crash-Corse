class Card {
  private:
    char suit;
    int value;
    
  public:
    Card(char,int);
    char getSuit();
    int getValue();
};

Card::Card(char theSuit, int theValue) {
  suit = theSuit;
  value = theValue;
}

char Card::getSuit() {
  return(suit);
}

int Card::getValue() {
  return(value);
}





class Deck {
  private:
    Card* cards[52];
    int topCard=0;

  public:
    Deck();
//    Card draw(Card);
    void reset();
    void shuffle();
};

Deck::Deck() {
  reset();
}

//Card Deck::draw(Card theCard) {
//  
//  int indexOfTheCard=-1;
//
//  for(int i=topCard; i<52; i++) {
//    if(cards[i].getSuit()==theCard.getSuit() && cards[i].getValue()==theCard.getValue()) {
//      indexOfTheCard = i;
//    }
//    
//  }
//
//  if(indexOfTheCrad==-1) {
//    return(cards[topCard]);
//  }
//  else {
//    Card temp;
//    temp = cards[topCard];
//    cards[topCard] = cards[indexOfTheCard];
//    cards[indexOfTheCard] = temp;
//
//    topCard++;
//    return(cards[topCard]);
//  }
//}

void Deck::reset() {
  int index=0;
  char suits[4] = {'H','C','S','D'};
  for(int i=0; i<4; i++) {
    for(int j=1; j<=13; j++) {
      cards[index] = new Card(suits[i],j);
      index++;
    }
  }  
}

void Deck::shuffle() {
  Card temp('S',1);
  int randomIndex;
  
  for(int i=0; i<52; i++) {
    randomIndex = random(52);
    temp = cards[i];
    cards[i] = cards[randomIndex];
    cards[randomIndex] = temp;
  }
}





void setup() {
  Serial.begin(9600);

  Card aceOfSpades('S',1);
  Serial.println(aceOfSpades.getSuit());
  Serial.println(aceOfSpades.getValue());

}

void loop() {
  
}
