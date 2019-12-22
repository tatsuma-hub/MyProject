@ECHO OFF

@SET EXE_PATH="C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Utilities\bin\x64\texconv.exe"

@ECHO テクスチャをDDSにコンバートします

@MD %~dp1DDS\

@for %%f in (%*) do (

@ECHO %%f

@(@%EXE_PATH% -w 1024 -h 1024 -ft dds -f DXT1 -m 8 -o %~dp1DDS\ %%f )

)


@PAUSE