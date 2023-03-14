## R CMD check results

#### There were no ERRORs.

#### There were no WARNINGs:

#### There were 1 NOTE:
##### checking for GNU extensions in Makefiles ... NOTE
#####  *GNU make is a SystemRequirements.

# Mar 13, 2023, BayesianPlatformDesignTimeTrend version 1.0.0 (resubmission)
## Major changes
I fixed some parts commented by the CRAN team, Benjamin Altmann.
I will describe the comments and their solution as follows.

> Please reduce the length of the title to less than 65 characters.

- I reduced the title to "Simulate and analyse Bayesian Platform Trial with time trend""

> Please omit the redundant "This Package" at the start of your title.

- I delete the "This Package" in title

> If there are references describing the methods in your package, please
> add these in the description field of your DESCRIPTION file in the form
> authors (year) <doi:...>
> authors (year) <arXiv:...>
> authors (year, ISBN:...)
> or if those are not available: <[https:...]https:...>
> with no space after 'doi:', 'arXiv:', 'https:' and angle brackets for
> auto-linking. (If you want to add a title as well please put it in
> quotes: "Title")

- I add reference about the analysis and randomisation methods used in this package.

> We see Unexecutable code in man/Randomisation.inf.Rd.
> I believe you have one closing bracket to much there.

- I revise the example in the man/Randomisation.inf.Rd

> You write information messages to the console that cannot be easily suppressed.
> It is more R like to generate objects that can be used to extract the information a user is interested in, and then print() that object.
> Instead of print()/cat() rather use message()/warning() or if(verbose)cat(..) (or maybe stop()) if you really have to write text to the console. (except for print, summary, interactive functions)
> -> R/Demo_CutoffScreening.R; R/Demo_multiplescenariotrialsimulation.R; R/TrialSimulation.R

- I modify the print() functions as follows.
- print("Start trial information initialisation") --> message("Start trial information initialisation")
- print("Start trial information initialisation") --> message("Start trial information initialisation")
- print(
    "Start trial simulation. This is a two arm trial simulation. There are two null scenarios and two alternative scenarios and for each scenario there are two vectors of number of patients at each stage in this demo. There are 8 rounds."
  ) --> message(
    "Start trial simulation. This is a two arm trial simulation. There are two null scenarios and two alternative scenarios and for each scenario there are two vectors of number of patients at each stage in this demo. There are 8 rounds."
  )
- print(paste(
        "Scenario",
        i,
        "with patient number sequence",
        ns[z],
        "under simulation"
      )) --> message(paste(
        "Scenario",
        i,
        "with patient number sequence",
        ns[z],
        "under simulation"
      ))
- print(paste("Finished round", cutoffindex)) --> message(paste("Finished round", cutoffindex))
- print("Start the start grid screening") --> message("Start the start grid screening")
- print(paste("Start the extend grid screening.","There are", grid.inf$extendlength ,"cutoff values under investigation in the extend grid")) --> message(paste("Start the extend grid screening.","There are", grid.inf$extendlength ,"cutoff values under investigation in the extend grid"))
- print(paste("Finished extend grid screening round", cutoffindex)) --> message(paste("Finished extend grid screening round", cutoffindex))
- print("Output data recording") --> message("Output data recording")


> Please make sure that you do not change the user's options, par or working directory. If you really have to do so within functions, please ensure with an *immediate* call of on.exit() that the settings are reset when the function is exited.
> e.g.:
> ...
> old <- options()# code line i
> on.exit(options(old)) # code line i+1
> ...
> options(...)# somewhere after
> ...
> e.g.: -> R/Demo_CutoffScreening.R; R/TrialSimulation.R
> If you're not familiar with the function, please check ?on.exit. This function makes it possible to restore options before exiting a function even if the function breaks. Therefore it needs to be called immediately after the option change within a function.