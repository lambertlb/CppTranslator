# Platform Support
This project is where all the support needed by .Net is provided by the target platform. This is separated
from the **DotNetLibrarySupport** project because that one depends on the **DotNetLibrary** and this one
should not.

In this example implementation this project is supplying a memory manager. It expects that no data or objects
will persist in the .Net world between runs. It therefore uses a memory pool that gets initialized before the run.
All data would need to be persisted on the platform side and be access as described in the
**DotNetLibrarySupport** README file.

This example is also not thread safe and only expects one translated algorithm to run at a time. If you
require multi-threading and or .Net data persistance then you will need to make a much fancier memory manager.
