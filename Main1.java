package sample;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Main1 extends Application {

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("00000000000");


         Button button =  new Button();
         button.setText("                                            tinh 1 + 1");
         button.setOnAction(new EventHandler<ActionEvent>() {
             @Override
             public void handle(ActionEvent event) {
                 System.out.println("1 + 1= " + (1 + 1));
             }
         });


         Button button1 = new Button();
         button1.setText("tinh 1 + 2");
         button1.setOnAction(new EventHandler<ActionEvent>() {
             @Override
             public void handle(ActionEvent event) {
                 System.out.println("1 + 2 =" + (1 + 2));
             }
         });

        StackPane layout = new StackPane();
        layout.getChildren().addAll(button, button1) ;
        Scene scene = new Scene (layout, 500, 400);

        primaryStage.setScene(scene) ;
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }


}
