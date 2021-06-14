
class CameraEffects extends PPEffects
{
	
	
	static float EXPOSURE = 0.0;
	static float CHROMABERX = 0.0;
	static float CHROMABERY = 0.0;
	static float HUESHIFT = 0.0;

	static float ROTBLUR = 0.0;
	static float MINDEPTH = 2.5;
	static float MAXDEPTH = 4.5;

	static float RADBLURX = 0.0;
	static float RADBLURY = 0.0;
	static float RADBLUROFFX = 0.0;
	static float RADBLUROFFY = 0.0;

	static float SHARPNESS = 0.0;
	static float GRAIN_SIZE = 0.0;

	static float VIGNETTE = 0.0;
	static float VARGB[4] = { 0, 0, 0, 0 };

	static float CARGB[4] = { 0, 0, 0, 1 }; 

	static float CAMERA_SMOOTH_BLUR = 0.0;

    protected float m_SmoothBlur;

    void CameraEffects()
    {

    }

    
	void init()
	{

	}

    
    static void changeChromaX(int value)
    {
    	Material chroma = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/chromaber");
        CHROMABERX = value;

        if(chroma)
        {
            chroma.SetParam( "PowerX", CHROMABERX );
        }
    }

    
    static void changeChromaY(int value)
    {
    	Material chroma = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/chromaber");
        CHROMABERY = value;

        if(chroma)
        {
            chroma.SetParam( "PowerY", CHROMABERY );
        }
    }

    
    static void setExposure(int value)
    {
        EXPOSURE = (value * 0.1) - 5.0;
	    GetGame().SetEVUser(EXPOSURE);
    }

	static void changeRadBlurXEffect(int intensity) 
	{
		Material radialBlur = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/radialblur");
		RADBLURX = (intensity * 0.01);

		if(radialBlur)
		{
            radialBlur.SetParam("PowerX", RADBLURX);
		}
	}

	static void changeRadBlurYEffect(int intensity) 
	{
		Material radialBlur = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/radialblur");
		RADBLURY = (intensity * 0.01);

		if(radialBlur)
		{
            radialBlur.SetParam("PowerY", RADBLURY);
		}
	}

	static void changeRadBlurXOffsetEffect(int intensity) 
	{
		Material radialBlur = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/radialblur");
		RADBLUROFFX = (intensity * 0.01);

		if(radialBlur)
		{
            radialBlur.SetParam("OffsetX", RADBLUROFFX);
		}
	}

	static void changeRadBlurYOffsetEffect(int intensity) 
	{
		Material radialBlur = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/radialblur");
		RADBLUROFFY = (intensity * 0.01);

		if(radialBlur)
		{
            radialBlur.SetParam("OffsetY", RADBLUROFFY);
		}
	}

	static void changeRotationBlurPower(int intensity) 
	{
		Material rotationBlur = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/rotblur");
		ROTBLUR = 0.5 * (intensity * 0.01);

        if(rotationBlur)
        {
            rotationBlur.SetParam("Power", ROTBLUR);
        }
	}

	static void changeRotationBlurDepth(int intensity) 
	{
		Material rotationBlur = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/rotblur");
		MINDEPTH = 2.5 * (intensity * 0.01);

		if(rotationBlur)
		{
            rotationBlur.SetParam("MinDepth", MINDEPTH);
		}
	}

	static void changeRotationBlurMaxDepth(int intensity) 
	{
		Material rotationBlur = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/rotblur");
		MAXDEPTH = (intensity * 0.1);

		if(rotationBlur)
		{
            rotationBlur.SetParam("MaxDepth", MAXDEPTH);
		}
	}


	static void changeVignette(int intensity) 
	{
		Material materialColors = GetGame().GetWorld().GetMaterial("graphics/gaterials/postprocess/glow");
		VIGNETTE = (intensity * 0.02);

		if(materialColors)
		{
		    materialColors.SetParam("Vignette", VIGNETTE);
		}
	}

	static void changeVignetteColorRGB(int R, int G, int B) 
	{
		Material materialColors = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/glow");
		VARGB[0] = R;
		VARGB[1] = G;
		VARGB[2] = B;

		if(materialColors)
		{
            materialColors.SetParam("VignetteColor", VARGB);
		}
	}

	static void changeOverlayColorRGB(int R, int G, int B, int overlay) 
	{
		Material materialColors = GetGame().GetWorld().GetMaterial("Graphics/Materials/postprocess/glow");
		CARGB[0] = R;
		CARGB[1] = G;
		CARGB[2] = B;
		CARGB[3] = ((overlay * 0.05) - 4.0);;


		if(materialColors)
		{
        	materialColors.SetParam("OverlayColor", CARGB);
		    materialColors.SetParam("OverlayFactor", CARGB[3]);
		}
	}

	static void changeHue(float intensity) 
	{
		Material materialColors = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/glow");
		HUESHIFT = (intensity * 0.1) - 5.0;

		if(materialColors)
		{
		    materialColors.SetParam( "Saturation", HUESHIFT);
		}
	}
	
	static void ResetSome()
	{
        CameraEffects.changeHue(60);
        CameraEffects.changeRadBlurXEffect(0);
	    CameraEffects.changeRadBlurYEffect(0);
		CameraEffects.changeRotationBlurPower(0);
		CameraEffects.changeVignette(0);
	}
	
};