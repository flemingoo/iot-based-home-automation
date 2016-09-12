package com.digitalenginedevelopers.smarthomecpanel;

import android.os.Bundle;
import android.os.StrictMode;
import android.util.Log;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;


import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;


/**
 * Created by flemms on 15-Apr-16.
 */

public class SettingsPanel extends MainActivity {
    public static SeekBar tempSeekRoom1;
    public static SeekBar lightSeekRoom1;
    public static SeekBar windowSeekRoom1;
    public static TextView tempTextRoom1;
    public static TextView lightTextRoom1;
    public static TextView windowTextRoom1;

    public static SeekBar tempSeekRoom2;
    public static SeekBar lightSeekRoom2;
    public static SeekBar windowSeekRoom2;
    public static TextView tempTextRoom2;
    public static TextView lightTextRoom2;
    public static TextView windowTextRoom2;

    public static SeekBar tempSeekRoom3;
    public static SeekBar lightSeekRoom3;
    public static SeekBar windowSeekRoom3;
    public static TextView tempTextRoom3;
    public static TextView lightTextRoom3;
    public static TextView windowTextRoom3;

    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        StrictMode.ThreadPolicy policy= new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);

        setContentView(R.layout.layout_auto_mode);
        tempSeekRoom1Method();
        lightSeekRoom1Method();
        windowSeekRoom1Method();

        //tempSeekRoom2Method();
        //lightSeekRoom2Method();
        //windowSeekRoom2Method();

        //tempSeekRoom3Method();
        //lightSeekRoom3Method();
        //windowSeekRoom3Method();
    }

    public void tempSeekRoom1Method(){
        tempSeekRoom1 = (SeekBar)findViewById(R.id.seekTempRoom1);
        tempTextRoom1 = (TextView)findViewById(R.id.tempValueRoom1);
        tempSeekRoom1.setMax(1023);
        tempSeekRoom1.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            int tempProgressRoom1;
            InputStream stream = null;
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                tempProgressRoom1 = progress;
                tempTextRoom1.setText("Value :" + tempProgressRoom1);
                //Toast.makeText(SettingsPanel.this, "Temperature changed", Toast.LENGTH_LONG).show();
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                //Toast.makeText(SettingsPanel.this, "Temperature Start Tracking", Toast.LENGTH_LONG).show();
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                List<NameValuePair> nameValuePairs=new ArrayList<NameValuePair>(1);
                nameValuePairs.add(new BasicNameValuePair("node", "node1"));
                nameValuePairs.add(new BasicNameValuePair("hvac", Integer.toString(tempProgressRoom1)));

                try {
                    HttpClient httpClient = new DefaultHttpClient();
                    HttpPost httpPost = new HttpPost("http://sh.digitalenginedevelopers.com/postData.php");
                    httpPost.setEntity(new UrlEncodedFormEntity(nameValuePairs));
                    HttpResponse response=httpClient.execute(httpPost);
                    HttpEntity entity=response.getEntity();
                    stream=entity.getContent();
                    String msg="Data entered Successfully";
                    Toast.makeText(getApplicationContext(),msg,Toast.LENGTH_LONG).show();
                }catch (ClientProtocolException e){
                    Log.e("ClientProtocol", "Log_Tag");
                    //e.printStackTrace();
                }
                catch (IOException e){
                    Log.e("Log_Tag", "IOException");
                    //e.printStackTrace();
                }
            }
        });
    }

    public void lightSeekRoom1Method(){
        lightSeekRoom1 = (SeekBar)findViewById(R.id.seekLightRoom1);
        lightTextRoom1 = (TextView)findViewById(R.id.lightValueRoom1);
        lightSeekRoom1.setMax(1023);
        lightSeekRoom1.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            int lightProgressRoom1;

            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                lightProgressRoom1 = progress;
                lightTextRoom1.setText("Value :"+ lightProgressRoom1);
                //Toast.makeText(SettingsPanel.this, "Light changed", Toast.LENGTH_LONG).show();
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                //Toast.makeText(SettingsPanel.this, "Light Start Tracking", Toast.LENGTH_LONG).show();
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                //Toast.makeText(SettingsPanel.this, "Light Start Tracking", Toast.LENGTH_LONG).show();
            }
        });
    }

    public void windowSeekRoom1Method(){
        windowSeekRoom1 = (SeekBar)findViewById(R.id.seekWindowRoom1);
        windowTextRoom1 = (TextView)findViewById(R.id.windowValueRoom1);
        windowSeekRoom1.setMax(1023);
        windowSeekRoom1.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            int windowProgressRoom1;

            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                windowProgressRoom1 = progress;
                windowTextRoom1.setText("Value :"+windowProgressRoom1);
                //Toast.makeText(SettingsPanel.this, "Window changed", Toast.LENGTH_LONG).show();
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                //Toast.makeText(SettingsPanel.this, "Window Start Tracking", Toast.LENGTH_LONG).show();
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                //Toast.makeText(SettingsPanel.this, "Window Stop Tracking", Toast.LENGTH_LONG).show();
            }
        });
    }

    public void tempSeekRoom2Method(){
        tempSeekRoom2 = (SeekBar)findViewById(R.id.seekTempRoom2);
        tempSeekRoom2.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            int tempProgressRoom2;
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                tempProgressRoom2 = progress;
                Toast.makeText(SettingsPanel.this , "Temperature changed", Toast.LENGTH_LONG).show();
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
    }

    public void tempSeekRoom3Method(){
        tempSeekRoom3 = (SeekBar)findViewById(R.id.seekTempRoom3);
        tempSeekRoom3.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            int tempProgressRoom3;
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                tempProgressRoom3 = progress;
                Toast.makeText(SettingsPanel.this , "Temperature changed", Toast.LENGTH_LONG).show();
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
    }
}
