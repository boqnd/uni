package game;

public enum Suit {
  CLUBS("CLUBS"), DIAMONDS("DIAMONDS"), HEARTS("HEARTS"), SPADES("SPADES");

  private String suit;

  private Suit(String value) {
    this.suit = value;
  }

  public String getSuit() {
    return this.suit;
  }
}