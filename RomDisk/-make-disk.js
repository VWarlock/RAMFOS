//----------------------------------------------------------------------------
// RAMFOS
// �������� ������ ����� �� ��������� ������
//
// 2013-11-01 ����������� vinxru
//----------------------------------------------------------------------------

// ���������

unmlzOffset	= 0x0063;
ramfosOffset	= 0x0430;
romdiskOffset	= 0x1800;
romdiskSize	= 0x10000-0x1800-11; // -romdiskOffset - page0start.length - page0end.length
loader1Offset	= 0x8000;

// ����������� ������

fso = new ActiveXObject("Scripting.FileSystemObject");
shell = new ActiveXObject("WScript.Shell");
function kill(name) { if(fso.FileExists(name)) fso.DeleteFile(name); }
function fileSize(name) { return fso.GetFile(name).Size; }
function loadAll(name) { return fso.OpenTextFile(name, 1, false, 0).Read(fileSize(name)); } // File.LoadAll ������ 
src = loadAll("tbl.bin"); encode = []; decode = []; for(i=0; i<256; i++) { encode[i] = src.charAt(i); decode[src.charCodeAt(i)] = i; }

// ������ ����������� ����� �����

function specialistSum(data) {
  s = 0;
  for(i=0; i<data.length-1; i++)
    s += decode[data.charCodeAt(i)] * 257;
  s = (s & 0xFF00) + ((s + decode[data.charCodeAt(i)]) & 0xFF);
  return (s & 0xFFFF);
}

// ������� ��������� �����

kill("list.tmp");

// �������� ������ ������

shell.Run("cmd /c dir /b /on *.* >list.tmp", 2, true);

// �����, ������� �� ���� ��������� �� ����

ignore = [];
ignore["list.tmp"] = 1;
ignore["tbl.bin"] = 1;
ignore["-make-disk.js"] = 1;

// ������������ ������ ����

dest = "";

list = fso.OpenTextFile("list.tmp", 1, false, 0);
while(!list.AtEndOfStream) {
  fileName = list.readLine();

  // ���� ���� �� �����

  if(ignore[fileName.toLowerCase()]) continue;

  // ��������� ����

  data = loadAll(fileName);
  fileStartAddr = romdiskOffset + dest.length;
  startAddr = 0;

  // �������� ����� ��������

  ext = fso.GetExtensionName(fileName).toUpperCase();
  if(ext == "RKS") {
    // �������� ����� �������� �� ��������� �����
    startAddr = decode[data.charCodeAt(0)] + decode[data.charCodeAt(1)] * 256;
    endAddr   = decode[data.charCodeAt(2)] + decode[data.charCodeAt(3)] * 256;
    len = endAddr - startAddr + 1;
    data = data.substr(4, len);    
  } else {
    // �������� ����� �������� �� ����� �����
    fileName = fso.GetBaseName(fileName);
    startAddr = fso.GetExtensionName(fileName) * 1;
  }

  // ��������� ����� Ramfos

  dest += encode[0xD3]+encode[0xD3]+encode[0xD3];
  dest += (fso.GetBaseName(fileName)+"        ").substr(0,8);
  dest += " ";
  dest += (ext+"   ").substr(0,3);  
  dest += encode[0x8C];
  dest += encode[0x01]+encode[0x11]+encode[0x13];
  dest += encode[0x00]+encode[0x00]+encode[0x00]+encode[0x00]+encode[0x00];
  dest += encode[startAddr & 0xFF]+encode[startAddr >> 8];
  endAddr = startAddr + data.length - 1;
  dest += encode[endAddr & 0xFF]+encode[endAddr >> 8];
  crc = specialistSum(data);  
  dest += encode[crc & 0xFF]+encode[crc >> 8];

  // ����

  dest += data;

  // � ����� ����� ��������� �� ������

  dest += encode[fileStartAddr & 0xFF]+encode[fileStartAddr >> 8];
}

// � ����� ����� ���� ����������

dest += encode[8];

// �������� �������

if(dest.length > romdiskSize) throw "������� ����� ������";
while(dest.length < romdiskSize) dest += encode[0];

// ���������

fso.CreateTextFile("../romdisk.bin", true).Write(dest);