#include <g4root.hh>
#include <Randomize.hh>

#include <iostream>



void write()
{
  G4cout << "write()" << G4endl;

  G4AnalysisManager* anamgr = G4AnalysisManager::Instance();

  G4cout << "Using " << anamgr->GetType() << G4endl;

  anamgr->OpenFile("output");

  G4int h1id = anamgr->CreateH1("h1", "Histogram Title", 10, 0., 1.);

  for (auto i=0; i<100; i++) anamgr->FillH1(h1id, G4UniformRand());

  G4cout << anamgr->GetH1(h1id)->mean() << G4endl;
  G4cout << anamgr->GetH1(h1id)->bin_height(0) << G4endl ;

  anamgr->Write();
  anamgr->CloseFile();

  delete anamgr;
}

void read()
{
  G4cout << "write()" << G4endl;

  auto anardr = G4AnalysisReader::Instance();

  G4int h1id = anardr->ReadH1("h1", "output");
  G4cout << anardr->GetH1(h1id)->mean() << G4endl;
  G4cout << anardr->GetH1(h1id)->bin_height(0) << G4endl ;

  delete anardr;
}


int main()
{
  G4cout << "main()" << G4endl;

  write();
  read();

  return 0;
}
