// @category BS2
import ghidra.app.script.GhidraScript;
public class PrepareBS2 extends GhidraScript {
 public void run() throws Exception {
  setAnalysisOption(currentProgram,"Non-Returning Functions - Discovered","false");
 }
}
