/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JulioFramework.Filters;

import Catalano.Imaging.FastBitmap;
import Catalano.Imaging.IApplyInPlace;

/**
 *
 * @author juliocmalvares
 */
public class InvertFilter implements IApplyInPlace{

    public InvertFilter() {
    }
    
    
    @Override
    public void applyInPlace(FastBitmap fb) {
        for (int i = 0; i < fb.getHeight(); i++) {
            for (int j = 0; j < fb.getWidth(); j++) {
                fb.setRed(i, j, 255 - fb.getRed(i, j));
                fb.setGreen(i, j, 255 - fb.getGreen(i, j));
                fb.setBlue(i, j, 255 - fb.getBlue(i, j));
            }

        }
    }
    
}
