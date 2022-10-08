module com.example.biovue {
    requires javafx.controls;
    requires javafx.fxml;
    requires bio.data;


    opens com.example.biovue to javafx.fxml;
    exports com.example.biovue;
}