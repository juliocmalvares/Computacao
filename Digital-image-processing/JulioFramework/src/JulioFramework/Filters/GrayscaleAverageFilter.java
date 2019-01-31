/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JulioFramework.Filters;

import Catalano.Imaging.FastBitmap;
import javax.swing.JOptionPane;

/**
 *
 * @author juliocmalvares
 */
public class GrayscaleAverageFilter implements Catalano.Imaging.IApplyInPlace{

    public GrayscaleAverageFilter() {
    }
    
    @Override
    public void applyInPlace(FastBitmap fb) {
        int mean = 0;
        for (int i = 0; i < fb.getHeight(); i++) {
            for (int j = 0; j < fb.getWidth(); j++) {
                mean = (int)(fb.getRed(i, j) + fb.getGreen(i, j) + fb.getBlue(i, j))/3;
                fb.setRed(i, j, mean);
                fb.setBlue(i, j, mean);
                fb.setGreen(i, j, mean);
                mean = 0;
            }
        }
    }
    
}
