import java.util.List;
import java.util.ArrayList;

public class InvoiceProcessing implements RandomItemFactory {
  List<Invoice> invoices;

  @Override
  public String apply(Integer num) {
    return RandomItemFactory.super.apply(num);
  }

  @Override
  public List<Item> get() {
    return RandomItemFactory.super.get();
  }

  public InvoiceProcessing(int count) {
    super();
    invoices = new ArrayList<Invoice>();

    for(int i = 0; i < count; i++) {
      Invoice in = new Invoice();
      in.items = get();
      invoices.add(in);
    }
  }

  public List<Invoice> getInvoices() {
    return invoices;
  }

  public void setInvoices(List<Invoice> invoices) {
    this.invoices = invoices;
  }

  public String showInvoices() {
    String res = "";

    for (Invoice invoice : invoices) {
      res += invoice.toString();
    }
    return res;
  }

  public double totalPrice() {
    double total = 0;

    for (Invoice invoice : invoices) {
      total+=invoice.totalInvoicePrice();
    }
    return total;
  }
}
