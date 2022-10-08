public class Item {
  String BARCODE;
  int quantity;
  double price;

  public Item() {
    super();
    BARCODE = "";
    quantity = 0;
    price = 0;
  }

  public String getBARCODE() {
    return BARCODE;
  }

  public double getPrice() {
    return price;
  }

  public int getQuantity() {
    return quantity;
  }

  public void setBARCODE(String bARCODE) {
    BARCODE = bARCODE;
  }

  public void setPrice(double price) {
    this.price = price;
  }

  public void setQuantity(int quantity) {
    this.quantity = quantity;
  }

  @Override
  public String toString() {
    return String.format("BARCODE : %s, Quantity : %2f, Price : %2f", BARCODE, quantity,price);
  }
}
