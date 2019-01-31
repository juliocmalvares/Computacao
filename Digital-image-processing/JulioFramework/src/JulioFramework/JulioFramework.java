/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JulioFramework;

import Catalano.Imaging.Concurrent.Filters.Invert;
import JulioFramework.Filters.GrayscaleAverageFilter;
import Catalano.Imaging.FastBitmap;
import Catalano.Imaging.Filters.GaussianBlur;
import Catalano.Imaging.Filters.GaussianBoxBlur;
import Catalano.Imaging.Filters.Grayscale;
import JulioFramework.Filters.AutomaticContrastFilter;
import JulioFramework.Filters.BrightnessFilter;
import JulioFramework.Filters.ContrastFilter;
import JulioFramework.Filters.InvertFilter;
import JulioFramework.Filters.LinearFilters.ConvolutionFilter;
import JulioFramework.Filters.LinearFilters.SobelEdgeDetectorFilter;
import JulioFramework.Filters.ThresholdFilter;
import javax.swing.JOptionPane;

/**
 *
 * @author juliocmalvares
 */
public class JulioFramework {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //Ler img
        FastBitmap imagem = new FastBitmap("/home/juliocmalvares/Documentos/8 Periodo/PDI/Imagens/cat2.jpg");  
        
  
        //BrightnessFilter br = new BrightnessFilter(25);
        //br.applyInPlace(imagem);

//        GrayscaleAverageFilter gr = new GrayscaleAverageFilter();
  //      gr.applyInPlace(imagem);
        
    //    InvertFilter inv = new InvertFilter();
      //  inv.applyInPlace(imagem);
        
//        SobelEdgeDetectorFilter sobel = new SobelEdgeDetectorFilter();
//        sobel.applyInPlace(imagem);

//        ThresholdFilter thr = new ThresholdFilter(130);
//        thr.applyInPlace(imagem);
        SobelEdgeDetectorFilter sb = new SobelEdgeDetectorFilter();
        sb.applyInPlace(imagem);
        
        
        //Mostrar img
        JOptionPane.showMessageDialog(null, imagem.toIcon());
    }
    
}
