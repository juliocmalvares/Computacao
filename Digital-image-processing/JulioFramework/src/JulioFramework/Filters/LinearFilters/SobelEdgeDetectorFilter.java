/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JulioFramework.Filters.LinearFilters;

import Catalano.Imaging.FastBitmap;
import Catalano.Imaging.Filters.Grayscale;
import Catalano.Imaging.IApplyInPlace;
import javax.swing.JOptionPane;
//import JulioFramework.Filters.GrayscaleAverageFilter;
//import javax.swing.JOptionPane;

/**
 *
 * @author juliocmalvares
 */
public class SobelEdgeDetectorFilter implements IApplyInPlace{
    private int[][] kernelHorizontal = {
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}
    
    };
    
    private int[][] kernelVertical = {
        {1, 0, -1},
        {2, 0, -2},
        {1, 0, -1}
    };
   
    private FastBitmap horizontal, vertical;

    public SobelEdgeDetectorFilter() {
        this.vertical = new FastBitmap();
        this.horizontal = new FastBitmap();
    }
    
    
    private void convolution(FastBitmap fb){
        Grayscale gr = new Grayscale();
        gr.applyInPlace(fb);
        
        this.horizontal.setImage(fb);
        this.vertical.setImage(fb);
        this.horizontal.Clear();
        this.vertical.Clear();
        
        for (int i = 0; i < fb.getHeight() - this.kernelHorizontal.length; i++) {
            for (int j = 0; j < fb.getWidth() - this.kernelHorizontal[0].length; j++) {
                double centroit = 0;
                for (int k = 0; k < this.kernelHorizontal.length; k++) {
                    for (int l = 0; l < this.kernelHorizontal[0].length; l++) {
                        centroit += fb.getGray(i+k,j+l) * this.kernelHorizontal[k][l];
                    }
                }
                
                centroit = centroit > 255 ? 255 : centroit;
                centroit = centroit < 0 ? 1 : centroit;               
                this.horizontal.setGray(i, j, (int)centroit);
            }
        }
       
        for (int i = 0; i < fb.getHeight() - this.kernelVertical.length; i++) {
            for (int j = 0; j < fb.getWidth() - this.kernelVertical.length; j++) {
                double centroit = 0;
                for (int k = 0; k < this.kernelVertical.length; k++) {
                    for (int l = 0; l < this.kernelVertical.length; l++) {
                        centroit += fb.getGray(i+k,j+l) * this.kernelVertical[k][l];
                    }
                }

                centroit = centroit > 255 ? 255 : centroit;
                centroit = centroit < 0 ? 1 : centroit; 
                this.vertical.setGray(i, j, (int)centroit);
            }
        }
    }
    
    
    @Override
    public void applyInPlace(FastBitmap fb) {
        this.convolution(fb);
        double pix = 0;
        for (int i = 0; i < fb.getHeight(); i++) {
            for (int j = 0; j < fb.getWidth(); j++) {
                pix = Math.sqrt(Math.pow(this.horizontal.getGray(i,j), 2) + Math.pow(this.vertical.getGray(i,j), 2));
                
                pix = pix > 255 ? 255 : pix;
                pix = pix <= 0 ? 1 : pix;
                //System.out.printf("Pix: %.2f\n", pix);
                fb.setGray(i,j, (int)pix);
            }
        }
    }
    
}
