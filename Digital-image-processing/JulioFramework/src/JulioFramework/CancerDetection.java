/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JulioFramework;

import Catalano.Imaging.FastBitmap;
import Catalano.Imaging.Filters.GaussianBoxBlur;
import Catalano.Imaging.Tools.ColorConverter;
import Catalano.Imaging.Tools.ConvolutionKernel;
import JulioFramework.Filters.BrightnessFilter;
import JulioFramework.Filters.ContrastFilter;
import JulioFramework.Filters.GrayscaleAverageFilter;
import JulioFramework.Filters.InvertFilter;
import JulioFramework.Filters.LinearFilters.ConvolutionFilter;
import JulioFramework.Filters.LinearFilters.SobelEdgeDetectorFilter;
import JulioFramework.Filters.NLinearFilters.Median;
import JulioFramework.Filters.NLinearFilters.Variance;
import JulioFramework.Filters.ThresholdFilter;
import javax.swing.JOptionPane;

/**
 *
 * @author juliocmalvares
 */
public class CancerDetection {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        FastBitmap imagem = new FastBitmap("/home/juliocmalvares/Documentos/8 Periodo/PDI/Imagens/Cancer/cancer.jpg");  
        JOptionPane.showMessageDialog(null, imagem.toIcon());
        Variance vr = new Variance(30);
        vr.applyInPlace(imagem);
        
  
//        BrightnessFilter br = new BrightnessFilter(-10);
//        br.applyInPlace(imagem);
     
//        GrayscaleAverageFilter gr = new GrayscaleAverageFilter();
//        gr.applyInPlace(imagem);
//        
////        InvertFilter inv = new InvertFilter();
////        inv.applyInPlace(imagem);
//        
//        GaussianBoxBlur bx = new GaussianBoxBlur(5,3);
//        bx.applyInPlace(imagem);
//        
//        ThresholdFilter thr = new ThresholdFilter(140, true);
//        thr.applyInPlace(imagem);
       
        //Mostrar img
        
        
        //adaptacao cromatica
//        double[] c1 = ColorConverter.RGBtoXYZ(200,80,20);
//        double[] c2 = ColorConverter.XYZtoLAB(c1[0], c1[1], c1[2], ColorConverter.CIE2_D65);
//        
//        //USAR Só a equaçaõ CIEDE2000
        JOptionPane.showMessageDialog(null, imagem.toIcon());
    }
    
}
