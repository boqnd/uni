package game;

public class Card {
  String face;
  String suit;

  public Card(Face face, Suit suit) {
    this.face = face.getFace();
    this.suit = suit.getSuit();
  }

  public void setFace(Face face) {
    this.face = face.getFace();
  }

  public void setSuit(Suit suit) {
    this.suit = suit.getSuit();
  }

  public String getFace() {
    return this.face;
  }

  public String getSuite() {
    return this.suit;
  }

  @Override
  public String toString() {
    return this.face + " of " + this.suit;
  }
}

