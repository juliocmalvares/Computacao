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
public class ContrastFilter implements IApplyInPlace{
    public double scale;

    public ContrastFilter(double scale) {
        this.scale = scale;
    }

    @Override
    public void applyInPlace(FastBitmap fb) {
        for (int i = 0; i < fb.getHeight(); i++) {
            for (int j = 0; j < fb.getWidth(); j++) {
                
                if(fb.getRed(i,j) * this.scale > 255) fb.setRed(i, j, 255);
                else if(fb.getRed(i, j) * this.scale < 0) fb.setRed(i,j, 0);
                else fb.setRed(i, j, (int) ((int)fb.getRed(i,j) * this.scale));
                
                if(fb.getGreen(i,j) * this.scale > 255) fb.setGreen(i, j, 255);
                else if(fb.getGreen(i, j) + this.scale < 0) fb.setGreen(i,j, 0);
                else fb.setGreen(i, j, (int) (fb.getGreen(i,j) * this.scale));
                
                
                if(fb.getBlue(i,j) * this.scale > 255) fb.setBlue(i, j, 255);
                else if(fb.getBlue(i, j) * this.scale < 0) fb.setBlue(i,j, 0);
                else fb.setBlue(i, j, (int) (fb.getBlue(i,j) * this.scale));
                
            }
        }
    }
    
}
