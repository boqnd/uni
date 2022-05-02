package game;

public enum Face {
  ACE("ACE"), KING("KING"), QUEEN("QUEEN"), JACK("JACK"), TEN("TEN"), NINE("NINE");

  private String face;

  private Face(String value) {
    this.face = value;
  }

  public String getFace() {
    return this.face;
  }
}