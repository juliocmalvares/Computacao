/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jfacerecognition;

import Catalano.Imaging.Concurrent.Filters.SobelEdgeDetector;
import Catalano.Imaging.Concurrent.Filters.Threshold;
import Catalano.Imaging.FastBitmap;
import Catalano.Imaging.Filters.BrightnessCorrection;
import Catalano.Imaging.Filters.ContrastCorrection;
import Catalano.Imaging.Filters.Photometric.SelfQuocientImage;
import Catalano.Imaging.Texture.BinaryPattern.LocalBinaryPattern;
import Catalano.Imaging.Tools.ImageHistogram;
import Catalano.Imaging.Tools.SpatialHistogram;
import Catalano.MachineLearning.Classification.DecisionTrees.Learning.GradientBoostingTree;
import Catalano.MachineLearning.Classification.DecisionTrees.Learning.RandomForest;
import Catalano.MachineLearning.Classification.IClassifier;
import Catalano.MachineLearning.Classification.KNearestNeighbors;
import Catalano.MachineLearning.Classification.MulticlassSupportVectorMachine;
import Catalano.MachineLearning.Classification.SupportVectorMachine;
import Catalano.MachineLearning.Dataset.DatasetClassification;
import Catalano.MachineLearning.Performance.KFoldCrossValidation;
import Catalano.Statistics.Kernels.ChiSquare;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JOptionPane;

/**
 *
 * @author juliocmalvares
 */
public class JFaceRecognition {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        File pasta = new File("dataset");
        File[] lista = pasta.listFiles();
        List<File> arquivos = new ArrayList<>();
        
        for(int i = 0; i < lista.length; i++){
            for(int k = 0; k < lista[i].listFiles().length; k++){
                arquivos.add(lista[i].listFiles()[k]);
            }
        }
        PGMReader reader = new PGMReader();
        List<FastBitmap> images = reader.read(arquivos);
        
   
        SpatialHistogram sh = new SpatialHistogram(15,15);
        double database[][] = new double[400][57600];
        int out[] = new int[400];
        
        int id = 0;
        int counter = 0;
        for(int i = 0; i < images.size(); i++){
            int input[] = sh.Compute(images.get(i), new LocalBinaryPattern());
            for(int k = 0; k < 57600; k++){
                database[i][k] = input[k]; 
            }
            counter++;
            if(counter % 10 == 0) id++;
            out[i] = id;
        }
        System.out.println("Database criada.");
        
        DatasetClassification dc = new DatasetClassification("rostos", database, out);
        IClassifier model = new KNearestNeighbors(3);
        KFoldCrossValidation val = new KFoldCrossValidation(10);
        System.out.print("Accuracy: " + val.Run(model, dc)+"\n");
        
//        double[] acuracias = new double[100];
//        for(int i = 1; i < 100; i++){
//            model = new KNearestNeighbors(i);
//            acuracias[i] = val.Run(model, dc);
//            System.out.println("K: "+i+ " Acurácia: "+acuracias[i]);
//        }
//        for(int i = 0; i < 100; i++) System.out.print(acuracias[i] + " ");
//        
//        
        System.out.println(model.Predict(dc.getInput()[199]));
        
//        LocalBinaryPattern lbp = new LocalBinaryPattern();
        
//        JOptionPane.showMessageDialog(null, lbp.toFastBitmap(images.get(0)).toIcon());
        

    }
    
}
