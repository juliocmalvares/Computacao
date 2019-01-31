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
public class ThresholdFilter implements IApplyInPlace{
    public int scale;
    public boolean invert = false;

    public ThresholdFilter(int scale) {
        this.scale = scale;
    }
    public ThresholdFilter(int scale, boolean invert){
        this.scale = scale;
        this.invert = invert;
    }

    @Override
    public void applyInPlace(FastBitmap fb) {
        for (int i = 0; i < fb.getHeight(); i++) {
            for (int j = 0; j < fb.getWidth(); j++) {
                if(!this.invert){
                    if(fb.getRed(i,j) > this.scale) fb.setRed(i, j, 255);
                    else fb.setRed(i, j, 0);

                    if(fb.getGreen(i,j) > this.scale) fb.setGreen(i, j, 255);
                    else fb.setGreen(i, j, 0);

                    if(fb.getBlue(i,j) > this.scale) fb.setBlue(i, j, 255);
                    else fb.setBlue(i, j, 0);
                }else{
                    if(fb.getRed(i,j) > this.scale) fb.setRed(i, j, 0);
                    else fb.setRed(i, j, 255);

                    if(fb.getGreen(i,j) > this.scale) fb.setGreen(i, j, 0);
                    else fb.setGreen(i, j, 255);

                    if(fb.getBlue(i,j) > this.scale) fb.setBlue(i, j, 0);
                    else fb.setBlue(i, j, 255);
                }
            }
        }
    }
    
}
