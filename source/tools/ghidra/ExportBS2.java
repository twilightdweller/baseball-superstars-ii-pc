// @category BS2
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class ExportBS2 extends GhidraScript {
 public void run() throws Exception {
  File dir=new File(getScriptArgs()[0]);dir.mkdirs();
  FunctionIterator reset=currentProgram.getFunctionManager().getFunctions(true);
  while(reset.hasNext()){Function f=reset.next();if(f.getName().startsWith("__aeabi_"))f.setNoReturn(false);}
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);
  FunctionIterator it=currentProgram.getFunctionManager().getFunctions(true);int count=0;
  while(it.hasNext()){
   Function f=it.next();String name=f.getName(true);
   if(!(name.contains("CBBStartUp")||name.contains("CBBGLogoRun")||name.contains("CBBGMenuRun")||name.contains("CGxZeroPZDParser")||name.contains("CBBGResMgr")||name.contains("handleCletEvent")||name.contains("DrawCaptureTitle")||name.contains("CGxPZFParser")||name.contains("CGxPZAParser")))continue;
   DecompileResults r=d.decompileFunction(f,45,monitor);
   try(PrintWriter w=new PrintWriter(new File(dir,f.getEntryPoint().toString()+".c"))){w.println("/* "+name+" at "+f.getEntryPoint()+"; decompiler output, not buildable source */");w.println(r.decompileCompleted()?r.getDecompiledFunction().getC():r.getErrorMessage());}
   count++;
  }
  d.dispose();println("EXPORTED "+count+" functions");
 }
}
