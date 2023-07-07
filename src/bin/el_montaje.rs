// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

use clap::error::{ContextKind, ContextValue, ErrorKind};
use clap::Parser;

use libferroxid_esolangs::esolangs::el_montaje::components::memory::Memory;
use libferroxid_esolangs::esolangs::el_montaje::components::processor_state::ProcessorState;
use libferroxid_esolangs::esolangs::el_montaje::tools::number;


#[derive(Parser, Debug)]
#[command(author, version, about, long_about = None)]
struct Cli {

    #[arg(short, long)]
    path: std::path::PathBuf,

    #[arg(short, long, default_value_t = String::from("1M"))]
    #[arg(help = "Memory size")]
    memory: String,
}

fn main() {
    let cli = Cli::parse();

    let _mem = Memory::new(cli.memory);
    let _processor_state = ProcessorState::new();
}
