#!/bin/bash
#SBATCH -A uoa04074
#SBATCH --job-name=mpi_pi
#SBATCH --output=mpi_pi_%j.log
#SBATCH -e slurm-%x.%A-%a.err
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --time=00:05:00
#SBATCH --mem=4GB

module load intel/2022a

mpirun ./mpi_pi
