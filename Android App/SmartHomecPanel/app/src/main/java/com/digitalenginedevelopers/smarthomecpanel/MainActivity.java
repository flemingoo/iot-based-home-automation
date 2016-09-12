package com.digitalenginedevelopers.smarthomecpanel;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    Button cPanelButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        cPanelButton = (Button)findViewById(R.id.cPanelButton);
        cPanelButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this,SettingsPanel.class);
                startActivity(intent);
            }
        });

    }
    /*public void showSettingsPanel(View view){
        String cPanelButtonText;
        cPanelButtonText = ((Button)view).getText().toString();
        if(cPanelButtonText.equals("showSettingsPanel")){
            Intent intent = new Intent(MainActivity.this,SettingsPanel.class);
                startActivity(intent);
        }
    }*/
}
