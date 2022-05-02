enum FaceOfCard {
  ACE("Ace"), DEUCE("Deuce"), THREE("Three"), FOUR("Four"), FIVE("Five"), SIX("Six"), SEVEN("Seven"), EIGHT("Eight"), NINE("Nine"), TEN("Ten"), JACK("Jack"), QUEEN("Queen"), KING("King");

  private String face;

  private FaceOfCard(String value) {
    this.face = value;
  }

  public String getFace() {
    return this.face;
  }
}

enum SuitOfCard {
  CLUBS("Clubs"), DIAMONDS("Diamonds"), HEARTS("Hearts"), SPADES("Spades");

  private String suit;

  private SuitOfCard(String value) {
    this.suit = value;
  }

  public String getSuite() {
    return this.suit;
  }
}

class Card {
  FaceOfCard face;
  SuitOfCard suit;

  public void setFace(FaceOfCard face) {
    this.face = face;
  }

  public void setSuit(SuitOfCard suit) {
    this.suit = suit;
  }

  public FaceOfCard getFace() {
    return this.face;
  }

  public SuitOfCard getSuite() {
    return this.suit;
  }

  public Card(FaceOfCard face, SuitOfCard suit) {
    this.face = face;
    this.suit = suit;
  }

  @Override
  public String toString() {
    return this.face + " of " + this.suit;
  }
}

class CardGameLib {
    public static void main(String[] args) {
        FaceOfCard f = FaceOfCard.ACE;
        SuitOfCard s = SuitOfCard.SPADES;

        Card c = new Card(f, s);

        System.out.println(c);
    }
}
