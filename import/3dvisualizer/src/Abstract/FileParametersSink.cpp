/***********************************************************************
FileParametersSink - Class for parameter sinks writing into simple text
files.
Part of the abstract interface to the templatized visualization
components.
Copyright (c) 2010 Oliver Kreylos

This file is part of the 3D Data Visualizer (Visualizer).

The 3D Data Visualizer is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation; either version 2 of the License, or (at
your option) any later version.

The 3D Data Visualizer is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License along
with the 3D Data Visualizer; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
***********************************************************************/

#include <Abstract/FileParametersSink.h>

#include <Misc/File.h>

namespace Visualization {

namespace Abstract {

/***********************************
Methods of class FileParametersSink:
***********************************/

FileParametersSink::FileParametersSink(const VariableManager* sVariableManager,Misc::File& sFile)
	:ParametersSink(sVariableManager),
	 file(sFile)
	{
	}

void FileParametersSink::write(const char* name,const WriterBase& value)
	{
	/* Write the value into a string: */
	std::string valueString;
	value.write(valueString);
	
	/* Write the string to the file: */
	file.puts("\t");
	file.puts(name);
	file.puts(" ");
	file.puts(valueString.c_str());
	file.puts("\n");
	}

void FileParametersSink::writeScalarVariable(const char* name,int scalarVariableIndex)
	{
	/* Get the variable's name: */
	std::string scalarVariableName=variableManager->getScalarVariableName(scalarVariableIndex);
	
	/* Write the variable's name to the file: */
	file.puts("\t");
	file.puts(name);
	file.puts(" ");
	file.puts(scalarVariableName.c_str());
	file.puts("\n");
	}

void FileParametersSink::writeVectorVariable(const char* name,int vectorVariableIndex)
	{
	/* Get the variable's name: */
	std::string vectorVariableName=variableManager->getVectorVariableName(vectorVariableIndex);
	
	/* Write the variable's name to the file: */
	file.puts("\t");
	file.puts(name);
	file.puts(" ");
	file.puts(vectorVariableName.c_str());
	file.puts("\n");
	}

}

}
