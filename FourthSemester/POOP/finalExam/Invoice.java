import java.util.List;
import java.util.ArrayList;

public class Invoice {
  String ID;
  List<Item> items;

  public Invoice() {
    super();
    ID = "";
    items = new ArrayList<Item>();
  }

  public String getID() {
    return ID;
  }

  public List<Item> getItems() {
    return items;
  }

  public void setID(String iD) {
    ID = iD;
  }

  public void setItems(List<Item> items) {
    this.items = items;
  }

  @Override
  public String toString() {
    String res = String.format("ID : %s" , ID);
    for (Item item : items) {
      res += item.toString();
    }
    return res;
  }

  public double totalInvoicePrice() {
    double total = 0;

    for (Item item : items) {
      total += item.price;
    }

    return total;
  }
}
