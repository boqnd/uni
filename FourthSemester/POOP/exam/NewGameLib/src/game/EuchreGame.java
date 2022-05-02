package game;

import java.util.Random;

public class EuchreGame {
  Card[] cards; // масив от всички карти в тестето от карти
  Card[] hand; // текущо изтеглена ръка от най- много 5 карти
  String TRUMP; // константа на всяка отделна игра
  Random random; // генератор на случайни числа
  int dealCard; // брой карти изтеглени текущо от cards

  public static Face[] faces = Face.values();
  public static Suit[] suits = Suit.values();

  public EuchreGame() {
    this.cards = new Card[24];

    for(int f=0; f<faces.length; f++) {
      for(int s=0; s<suits.length; s++) {
        cards[f*4+s] = new Card(faces[f], suits[s]);
      }
    }
    random = new Random();

    this.TRUMP = suits[random.nextInt(4)].getSuit();

    this.shuffleCards();
  }

  public String getTrump() {
    return this.TRUMP;
  }

  private void shuffleCards() {
    this.dealCard = 0;

    for(int i=0; i<cards.length; i++) {
      int index = random.nextInt(cards.length);

      Card temp = cards[index];
      cards[index] = cards[i];
      cards[i] = temp;
    }
  }

  public void printCards() {
    for(int i = 0; i<this.cards.length; i++) {
      System.out.println(cards[i]);
    }
  }

  public void printHand() {
    for(int i = 0; i<this.hand.length; i++) {
      System.out.println(this.hand[i]);
    }
  }

  public boolean dealHand() {
    if (this.cards.length < 5) {
      this.hand = new Card[this.cards.length];
      this.dealCard = this.cards.length;

      for (int i=0; i<this.cards.length; i++) {
        this.hand[i] = this.cards[i];
      }
      this.cards = new Card[0];

      return false;
    } else {
      this.hand = new Card[5];
      this.dealCard = 5;

      for (int i=0; i<5; i++) {
        this.hand[i] = this.cards[i];
      }

      Card[] temp = new Card[this.cards.length];
      for (int i = 0; i < cards.length; i++) {
        temp[i] = cards[i];
      }

      this.cards = new Card[temp.length-5];

      for (int i = 5; i<temp.length; i++) {
        this.cards[i-5] = temp[i];
      }

      return true;
    }
  }

  public int countHandStrength() {
    int res = 0;

    for (int i = 0; i<this.hand.length; i++) {
      switch (hand[i].getFace()) {
        case "ACE":
          res += 6;
          break;
        case "KING":
          res += 5;
          break;
        case "QUEEN":
          res += 4;
          break;
        case "JACK":
          res += 3;
          break;
        case "TEN":
          res += 2;
          break;
        case "NINE":
          res += 1;
          break;
      }
    }

    return res;
  }

  public boolean hasJackQueenKingTrump() {
    boolean jack = false;
    boolean queen = false;
    boolean king = false;

    for (int i = 0; i < this.hand.length; i++) {
      if(hand[i].getFace() == "JACK" && hand[i].getSuite() == this.TRUMP) {
        jack = true;
      }else if(hand[i].getFace() == "QUEEN" && hand[i].getSuite() == this.TRUMP) {
        queen = true;
      } else  if(hand[i].getFace() == "KING" && hand[i].getSuite() == this.TRUMP) {
        king = true;
      }
    }

    return (jack && queen && king);
  }

  public boolean hasJackANDAceTrump() {
    boolean jack = false;
    boolean ace = false;

    for (int i = 0; i < this.hand.length; i++) {
      if(hand[i].getFace() == "JACK" && hand[i].getSuite() == this.TRUMP) {
        jack = true;
      }else if(hand[i].getFace() == "ACE" && hand[i].getSuite() == this.TRUMP) {
        ace = true;
      }
    }

    return (jack && ace);
  }
}
