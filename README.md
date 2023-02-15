<table border=0 cellpadding=0 cellspacing=0 valign='top'><tr>
<td><a href='https://www.getmangos.eu' target='getmangos.eu'><img src='https://www.getmangos.eu/!assets_mangos/logo.png' border=0></a></td>
<td valign='top'>
<a href='https://www.getmangos.eu/forums/' target='getmangos.forum'><img src='/icons/FORUM.gif' border=0></a>
<a href='https://www.getmangos.eu/wiki' target='getmangos.wiki'><img src='/icons/WIKI.gif' border=0></a>
<a href='https://www.getmangos.eu/github-activity/' target='getmangos.activity'><img src='/icons/ACTIVITY.gif' border=0></a>
<a href='https://www.getmangos.eu/bug-tracker/mangos-zero/' target='getmangos.tracker'><img src='/icons/TRACKER.gif' border=0></a>
</td></tr></table>

Mangos Dependencies
------------
*Mangos* stands on the shoulders of well-known Open Source
libraries, and a few awesome, but less known libraries to prevent us from
reinventing the wheel.

*Please note that Linux and Mac OS X users should install packages using
their systems package management instead of source packages.*

* **ACE**: the [ADAPTIVE Communication Environment][1] aka. *ACE* provides us
  with a solid cross-platform framework for abstracting operating system
  specific details.
* **Recast & Detour**: in order to create navigation data from the client's map
  files, we use [Recast/Detour][2] to do the dirty work.
* **G3D**: the [G3D][3] engine provides the basic framework for handling 3D
  data, and is used to handle basic map data.
* **StormLib**: [StormLib][4] provides an abstraction layer for reading from the
  client's data files.
* **Zlib**: [Zlib][5] provides compression algorithms used in both MPQ archive
  handling and the client/server protocol.
* **Bzip2**: [Bzip2][6] provides compression algorithms used in MPQ archives.
* **Lua**: [Lua 5.2][7] provides a convenient, fast scripting environment, which
  allows us to make live changes to scripted content.


Optional dependencies
---------------------

* **Doxygen**: if you want to export HTML or PDF formatted documentation for the
  *Mangos* API, you should install [Doxygen][9].

[1]: http://www.cs.wustl.edu/~schmidt/ACE.html "ACE The ADAPTIVE Communication Environment"
[2]: https://github.com/recastnavigation/recastnavigation "Recast Navigation-mesh Toolset for Games"
[3]: https://casual-effects.com/g3d/www/index.html "G3D G3D Innovation Engine"
[4]: http://www.zezula.net/en/mpq/stormlib.html "A library for reading data from MPQ archives"
[5]: https://www.zlib.net/ "Zlib - A Massively Spiffy Yet Delicately Unobtrusive Compression Library"
[6]: https://sourceware.org/bzip2/ "Bzip2"
[7]: http://www.lua.org/ "Lua - powerful, efficient, lightweight, embeddable scripting language"
[9]: https://www.doxygen.nl "Doxygen - de facto standard tool for generating documentation from annotated C++ sources"
