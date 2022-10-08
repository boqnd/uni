package com.example.biovue;

import java.net.URL;
import java.util.*;

import bio.data.Animal;
import bio.data.AnimalInstance;
import bio.data.AnimalType;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextArea;

public class HelloController {
    private AnimalInstance[] samples;
    private Animal[] animals;

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private MenuItem MIDistribution;

    @FXML
    private MenuItem MIQuit;

    @FXML
    private MenuItem MIShow;

    @FXML
    private MenuItem MIShuffle;

    @FXML
    private MenuItem MISort;

    @FXML
    private TextArea txaOutput;

    @FXML
    void MIDistributionOnAction(ActionEvent event) {
        Map<String, Integer> map = new HashMap<>();

        for (String reg: Animal.REGIONS) {
            List<Animal> animalList = Arrays.stream(animals).filter(a -> a.getRegion().equals(reg)).toList();

            int count = 0;
            for (Animal animal: animalList) {
                count += Arrays.stream(samples).filter(a -> a.getAnimalName().equals(animal.getName())).toList().size();
            }

            map.put(reg, count);
        }

        txaOutput.setText("");
        for (Map.Entry<String, Integer> a :
                map.entrySet()) {
            txaOutput.appendText(a.toString() + "\n");
        }
    }

    @FXML
    void MIQuitOnAction(ActionEvent event) {
        Platform.exit();
    }

    @FXML
    void MIShowOnAction(ActionEvent event) {
        Map<String, Integer> map = new HashMap<>();

        for (AnimalType type: AnimalType.values()) {
            List<Animal> animalList = Arrays.stream(animals).filter(a -> a.getAnimalType().equals(type) && a.isEndangered()).toList();

            int count = 0;
            for (Animal animal: animalList) {
                count += Arrays.stream(samples).filter(a -> a.getAnimalName().equals(animal.getName())).toList().size();
            }

            map.put(type.getTypeName(), count);
        }

        txaOutput.setText("");
        for (Map.Entry<String, Integer> a :
                map.entrySet()) {
            txaOutput.appendText(a.toString() + "\n");
        }
    }

    @FXML
    void MIShuffleOnAction(ActionEvent event) {
        Collections.shuffle(Arrays.asList(samples));
        txaOutput.setText("");
        for (AnimalInstance a :
                samples) {
            txaOutput.appendText(a.toString() + "\n");
        }
    }

    @FXML
    void MISortOnAction(ActionEvent event) {
        Arrays.sort(samples, Comparator.comparing(AnimalInstance::getAnimalAge));
        txaOutput.setText("");
        for (AnimalInstance a :
                samples) {
            txaOutput.appendText(a.toString() + "\n");
        }
    }

    @FXML
    void initialize() {
        assert MIDistribution != null : "fx:id=\"MIDistribution\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert MIQuit != null : "fx:id=\"MIQuit\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert MIShow != null : "fx:id=\"MIShow\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert MIShuffle != null : "fx:id=\"MIShuffle\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert MISort != null : "fx:id=\"MISort\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert txaOutput != null : "fx:id=\"txaOutput\" was not injected: check your FXML file 'hello-view.fxml'.";

        animals = new Animal[] {
                new Animal("Тигър", AnimalType.MAMMAL, true, "Asia", true),
                new Animal("Фламинго", AnimalType.BIRD, false, "Africa", true),
                new Animal("Гущер", AnimalType.REPTILE, true, "Australia", true),
                new Animal("Пъстърва", AnimalType.FISH, false, "Europe", false),
                new Animal("Делфин", AnimalType.MAMMAL, false, "Australia", true),
                new Animal("Вълк", AnimalType.MAMMAL, true, "America", false)
        };

        Random random = new Random();

        samples = new AnimalInstance[20];

        for (int i = 0; i < 20; i++) {
            int key = random.nextInt(animals.length);

            samples[i] = new AnimalInstance(key, animals[key].getName(), random.nextInt(10, 31));
        }
    }

}
