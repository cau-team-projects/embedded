/*
 * Copyright 2013 Simon Willeke
 * contact: hamstercount@hotmail.com
 */

package org.blockinger.game;

import org.blockinger.game.activities.GameActivity;

import android.graphics.Canvas;
import android.preference.PreferenceManager;
import android.view.SurfaceHolder;

public class WorkThread extends Thread {
	static {
		System.loadLibrary("pushbutton");
	}

	public native int getInputStatus(int prev);

	public int previousInput;
	private SurfaceHolder surfaceHolder;
    private boolean runFlag = false;
    boolean firstTime = true;
	public long lastFrameDuration = 0;
	private long lastFrameStartingTime = 0;
	int fpslimit;
	long lastDelay;
	private GameActivity host;

    public WorkThread(GameActivity ga, SurfaceHolder sh) {
    	host = ga;
		this.surfaceHolder = sh;
        try {
        	fpslimit = Integer.parseInt(PreferenceManager.getDefaultSharedPreferences(host).getString("pref_fpslimittext", "35"));
        } catch(NumberFormatException e) {
        	fpslimit = 25;
        }
        if(fpslimit < 5)
        	fpslimit = 5;
        
		lastDelay = 100;
    }

    public void setRunning(boolean run) {
        this.runFlag = run;
    }

    public void execute(int button_pressed) {
    	switch(button_pressed) {
			case 0 :
				// rotate left
				host.controls.rotateLeftPressed();
				host.controls.rotateLeftReleased();
				break;
			case 1 :
				// hard drop
				host.controls.dropButtonPressed();
				host.controls.dropButtonReleased();
				break;
			case 2 :
				// rotate right
				host.controls.rotateRightPressed();
				host.controls.rotateRightReleased();
				break;
			case 3 :
				// left
				host.controls.leftButtonPressed();
				host.controls.leftButtonReleased();
				break;
			case 4 :
				// center button : ??
				break;
			case 5 :
				// right
				host.controls.rightButtonPressed();
				host.controls.rightButtonReleased();
				break;
			case 6 :
				// rotate left
				host.controls.rotateLeftPressed();
				host.controls.rotateLeftReleased();
				break;
			case 7 :
				// soft drop
				host.controls.downButtonPressed();
				host.controls.downButtonReleased();
				break;
			case 8 :
				// rotate right
				host.controls.rotateRightPressed();
				host.controls.rotateRightReleased();
				break;
		}
	}

    @Override
    public void run() {
        Canvas c;
        long tempTime = System.currentTimeMillis();

		long fpsUpdateTime = tempTime + 200;
		int frames = 0;
		int frameCounter[] = {0, 0, 0, 0, 0};
		int i = 0;
        
        while (this.runFlag) {
	            if(firstTime){
	            	firstTime = false;
	            	continue;
	            }
	            
	            /* FPS CONTROL */
	            tempTime = System.currentTimeMillis();
	            
	            try {
	            	fpslimit = Integer.parseInt(PreferenceManager.getDefaultSharedPreferences(host).getString("pref_fpslimittext", "35"));
	            } catch(NumberFormatException e) {
	            	fpslimit = 35;
	            }
	            if(fpslimit < 5)
	            	fpslimit = 5;
	            
	            if(PreferenceManager.getDefaultSharedPreferences(host).getBoolean("pref_fpslimit", false)) {
		            lastFrameDuration = tempTime - lastFrameStartingTime;
		            if(lastFrameDuration > (1000.0f/fpslimit))
		            	lastDelay = Math.max(0, lastDelay - 25);
		            else
		            	lastDelay+= 25;
		            
		            if(lastDelay == 0) {} // no Sleep
		            else {
			            try {// do sleep!
							Thread.sleep(lastDelay);
						} catch (InterruptedException e) {
							// e.printStackTrace(); ignore this shit
						}
		            }
		            lastFrameStartingTime = tempTime;
	            }
	            
	            if(tempTime >= fpsUpdateTime) {
	            	i = (i + 1) % 5;
		    		fpsUpdateTime += 200;
		    		frames = frameCounter[0] + frameCounter[1] + frameCounter[2] + frameCounter[3] + frameCounter[4];
		            frameCounter[i] = 0;
	            }
	            frameCounter[i]++;
	            /* END OF FPS CONTROL*/

				int temp = getInputStatus(previousInput);
				switch(temp) {
					case -3 :
						// persisting
						break;
					case -2 :
						// not_pressed
						previousInput = -2;
						break;
					case -1 :
						// error
						break;
					default :
						previousInput = temp;
						execute(previousInput);
						break;
				}


	            if(host.game.cycle(tempTime))
	            	host.controls.cycle(tempTime);
	            host.game.getBoard().cycle(tempTime);
	            
	            c = null;
	            try {
	               
	                c = this.surfaceHolder.lockCanvas(null);
	                synchronized (this.surfaceHolder) {                   
	                    host.display.doDraw(c, frames);
	                }
	            } finally {
	               
	                if (c != null) {
	                    this.surfaceHolder.unlockCanvasAndPost(c);
	                    
	                }
	            }
        }
    }

	public void setFirstTime(boolean b) {
		firstTime = b;
	}

}