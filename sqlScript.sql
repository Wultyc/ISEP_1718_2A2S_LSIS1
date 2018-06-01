-- MySQL Script generated by MySQL Workbench
-- Wed May 30 11:07:57 2018
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema robo
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema robo
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `robo` DEFAULT CHARACTER SET utf8 ;
USE `robo` ;

-- -----------------------------------------------------
-- Table `robo`.`Equipas`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `robo`.`Equipas` ;

CREATE TABLE IF NOT EXISTS `robo`.`Equipas` (
  `idEquipas` INT NOT NULL AUTO_INCREMENT,
  `nome` VARCHAR(45) NULL,
  PRIMARY KEY (`idEquipas`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `robo`.`robo`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `robo`.`robo` ;

CREATE TABLE IF NOT EXISTS `robo`.`robo` (
  `idrobo` INT NOT NULL AUTO_INCREMENT,
  `nome` VARCHAR(45) NULL,
  `Equipas_idEquipas` INT NOT NULL,
  PRIMARY KEY (`idrobo`, `Equipas_idEquipas`),
  INDEX `fk_robo_Equipas_idx` (`Equipas_idEquipas` ASC),
  CONSTRAINT `fk_robo_Equipas`
    FOREIGN KEY (`Equipas_idEquipas`)
    REFERENCES `robo`.`Equipas` (`idEquipas`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `robo`.`Elementos`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `robo`.`Elementos` ;

CREATE TABLE IF NOT EXISTS `robo`.`Elementos` (
  `idElementos` INT NOT NULL AUTO_INCREMENT,
  `elemento` VARCHAR(45) NULL,
  `Equipas_idEquipas` INT NOT NULL,
  PRIMARY KEY (`idElementos`, `Equipas_idEquipas`),
  INDEX `fk_Elementos_Equipas1_idx` (`Equipas_idEquipas` ASC),
  CONSTRAINT `fk_Elementos_Equipas1`
    FOREIGN KEY (`Equipas_idEquipas`)
    REFERENCES `robo`.`Equipas` (`idEquipas`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `robo`.`Prova`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `robo`.`Prova` ;

CREATE TABLE IF NOT EXISTS `robo`.`Prova` (
  `idProva` INT NOT NULL AUTO_INCREMENT,
  `data` DATE NULL,
  `local` VARCHAR(45) NULL,
  `robo_idrobo` INT NOT NULL,
  PRIMARY KEY (`idProva`, `robo_idrobo`),
  INDEX `fk_Prova_robo1_idx` (`robo_idrobo` ASC),
  CONSTRAINT `fk_Prova_robo1`
    FOREIGN KEY (`robo_idrobo`)
    REFERENCES `robo`.`robo` (`idrobo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `robo`.`States`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `robo`.`States` ;

CREATE TABLE IF NOT EXISTS `robo`.`States` (
  `idStates` INT NOT NULL AUTO_INCREMENT,
  `state` INT(1) NULL,
  `data` DATE NULL,
  `Prova_idProva` INT NOT NULL,
  PRIMARY KEY (`idStates`, `Prova_idProva`),
  INDEX `fk_States_Prova1_idx` (`Prova_idProva` ASC),
  CONSTRAINT `fk_States_Prova1`
    FOREIGN KEY (`Prova_idProva`)
    REFERENCES `robo`.`Prova` (`idProva`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
